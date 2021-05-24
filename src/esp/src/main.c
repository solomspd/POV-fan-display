#include "driver/i2c.h"
#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <esp_wifi.h>
#include <esp_event_loop.h>
#include <esp_log.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include <esp_http_server.h>

#define I2C_SCL_IO 22
#define I2C_SDA_IO 21
#define I2C_FREQ_HZ 100000

#define BUF_SZ 25
#define EXAMPLE_WIFI_SSID "Abdo1_2.4GHz" 
#define EXAMPLE_WIFI_PASS "abdsalam"

char word[BUF_SZ];

static const char *TAG="APP";
bool status=true;

uint8_t buffer[BUF_SZ];

static esp_err_t i2c_master_write_slave_reg(i2c_port_t i2c_num, uint8_t i2c_addr, uint8_t* data_wr, size_t size)
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, ( i2c_addr << 1 ) | I2C_MASTER_WRITE, true);
    i2c_master_write(cmd, data_wr, size, true);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(i2c_num, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

static void i2c_master_init()
{
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_SDA_IO;
    conf.scl_io_num = I2C_SCL_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_FREQ_HZ;
    ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0));
}

esp_err_t hello_get_handler(httpd_req_t *req)
{
    char*  buf;
    size_t buf_len;

    buf_len = httpd_req_get_hdr_value_len(req, "Host") + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        /* Copy null terminated value string into buffer */
        if (httpd_req_get_hdr_value_str(req, "Host", buf, buf_len) == ESP_OK) {
        }
        free(buf);
    }

    buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
            ESP_LOGI(TAG, "Found URL query => %s", buf);
            char param[32];
            /* Get value of expected key from query string */
        }
        free(buf);
    }

	char resp_str [500]= "<head>ESP32 server</head><h1 style=\"color:blue;\">Enter The message below</h1><form action=\"/../capture\" method=\"POST\" ><label for=\"fname\">Message:</label><br /><input id=\"fname\" name=\"fname\" type=\"text\" value=\"hello\" /><br /><br /<input type=\"submit\" value=\"Submit\" /></form>";
    
    

    

    httpd_resp_send(req, resp_str, 500);

    return ESP_OK;
}



esp_err_t post_handler(httpd_req_t *req){
   char content[500];

   size_t recv_size = MIN(req->content_len, sizeof(content));

   int ret = httpd_req_recv(req,content,recv_size);
   	
   memset(word, 0, sizeof(word));
   for (int i = 6; i <req->content_len; i++)
	word[i-6] = content[i];
	
   printf(word);
   esp_err_t i2c_ret = ESP_OK;
   i2c_ret = i2c_master_write_slave_reg(I2C_NUM_0, 0x4A, (uint8_t*)word, sizeof(word));
    if(i2c_ret != ESP_OK)
    {
        printf("Error!!\r\n"); 
    }
    else 
    {
        printf("success!!\r\n");
    }
   return ESP_OK;
}

httpd_uri_t hello = {
    .uri       = "/start",
    .method    = HTTP_GET,
    .handler   = hello_get_handler,
    .user_ctx  = "NULL"
};
httpd_uri_t capture = {
    .uri = "/capture",
    .method = HTTP_POST,
    .handler = post_handler,
    .user_ctx = NULL
    };


httpd_handle_t start_webserver(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    // Start the httpd server
    if (httpd_start(&server, &config) == ESP_OK) {
        // Set URI handlers
        httpd_register_uri_handler(server, &hello);

        httpd_register_uri_handler(server, &capture);
        return server;
    }

    return NULL;
}

static esp_err_t event_handler(void *ctx, system_event_t *event)
{
    httpd_handle_t *server = (httpd_handle_t *) ctx;

    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
        ESP_ERROR_CHECK(esp_wifi_connect());
        break;

    case SYSTEM_EVENT_STA_GOT_IP:
        if (*server == NULL) {
            *server = start_webserver();
        }
        break;

    case SYSTEM_EVENT_STA_DISCONNECTED:
        ESP_LOGI(TAG, "SYSTEM_EVENT_STA_DISCONNECTED");
        ESP_ERROR_CHECK(esp_wifi_connect());

        /* Stop the web server */
        if (*server) {
            httpd_stop(server);
            *server = NULL;
        }
        break;

    default:
        break;

    }
    return ESP_OK;
}

static void initialise_wifi(void *arg)
{
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_init(event_handler, arg));
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_WIFI_SSID,
            .password = EXAMPLE_WIFI_PASS,
        },
    };
    ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", wifi_config.sta.ssid);
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void app_main()
{
    i2c_master_init();
    static httpd_handle_t server = NULL;
    ESP_ERROR_CHECK(nvs_flash_init());
    initialise_wifi(&server);
}

// void app_main() 
// {
//     esp_err_t i2c_ret = ESP_OK;
// 	sprintf((char*)buffer, "asd");
//     i2c_master_init();
//     while(1)
//     {
//         i2c_ret = i2c_master_write_slave_reg(I2C_NUM_0, 0x4A, buffer, sizeof(buffer));
//         if(i2c_ret != ESP_OK)
//         {
//             printf("Error!!\r\n"); 
//         }
//         else 
//         {
//             printf("success!!\r\n");
//         }
//         vTaskDelay(100);
//     }
// }