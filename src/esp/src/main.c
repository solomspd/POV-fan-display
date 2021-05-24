#include "driver/i2c.h"
#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

// #define SAMPLE_PERIOD_MS		200

#define I2C_SCL_IO				22	//19    orange     /*!< gpio number for I2C master clock */
#define I2C_SDA_IO				21	//18    yellow     /*!< gpio number for I2C master data  */
#define I2C_FREQ_HZ				100000           /*!< I2C master clock frequency */

#define BUF_SZ 25

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

void app_main() 
{
    esp_err_t i2c_ret = ESP_OK;
	sprintf((char*)buffer, "asd");
    i2c_master_init();
    while(1)
    {
        i2c_ret = i2c_master_write_slave_reg(I2C_NUM_0, 0x4A, buffer, sizeof(buffer));
        if(i2c_ret != ESP_OK)
        {
            printf("Error!!\r\n"); 
        }
        else 
        {
            printf("success!!\r\n");
        }
        vTaskDelay(100);
    }
}