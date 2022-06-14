# Persistance of Vision Fan Display

## Repository
https://github.com/solomspd/Embedded-Project-2

A novel approach to creating images is through a Persistance Of Vision (POV) fan display.

Essentially, it is a fixture of a platform mounted on a motor that spins at high speeds so that you can no longer see the individual LED lights.
Then, the LEDs would light up at certain intervals so that it seems to the human eye that there is 1 cohesive image.

Beyond this base functionality, there can be a webpage that allows a user to input a string of text that will be correctly processed and displayed on the POV display.

This display can have the ability to not only display text, including a digital clock, but also any art such as an analog clock.

The display should also be able to support any speed of rotation and be able to cope with dynamically changing it.

## Design
All logic will be placed inside the rotating blade itself so that we do not need to worry about power delivery to the MCU controller and for them to have their own independent battery rotating with them.
So within the blade would be the LED strip, the Nucleo MCU and the ESP32 MCU.
The Nucleo MCU will be the heart of the system, is directly connected to both the strip and an IR sensor.
The IR sensor is needed since we are using a dumb DC motor to drive the blade, so there is no way of knowing the RPM of the motor.
To resolve this, we use an IR sensor to keep track of how much time a single revolution takes.

The ESP32 MCU is there so that it can communicate with the Nucleo, updating it with new visuals requested by the user.
The ESP32 will also serve the front end to the user in the form of a webpage where they can enter new text.

Beyond the blade, the DC motor operates using a motor driver so that we can control its speed.
This speed control is carried out very simply with an Arduino that is only there to supply the motor driver with a PWM signal so we can dynamically change the speed of the motor.

![architecture of system](https://github.com/solomspd/Embedded-Project-2/blob/master/proposals/schematic.png)

## Challenges
- A clear challenge in accomplishing this is a mechanical one; getting the hardware physically configured correctly and ensuring stability at high speeds.
- Synchronizing the display with the period of a single revolution of the motor so the image can appear to stay in place.

## Limitations
- Distortion will be induced in any image that we attempt to display. This distortion is due to the fact that the LEDs are of different distances from the center of the rotating circle. So, LEDs that are far from the center will have a bigger arc to move within. For example, when displaying the letter E, the upper edge will look wider than the lower ones.

- The length and resolution of messages capable of being displayed. We can update the LEDs only as fast as the MCU allows and remains readable. Thus, we can allow only a specific number of letters based time each letter takes to display. The resolution of a character is limited according to the number of LEDs on the rotating edge.


# Prototype

![prototype image](https://github.com/solomspd/Embedded-Project-2/blob/master/proposals/front_proto.png)
![First Word!](https://github.com/solomspd/Embedded-Project-2/blob/master/pic1.jpeg)
![Second Word!](https://github.com/solomspd/Embedded-Project-2/blob/master/pic2.jpeg)
![Webpage](https://cdn.discordapp.com/attachments/822888716535463946/846298184040579112/unknown.png)

Demo: https://youtu.be/ix53WhJILdo

## How it works
The circular fan is divided up into sectors; the number of sectors is determined by the user and the speed of the STM3L432.
Each sector defines the configuration of the LEDs for that slice.
This allows us to create an array, each 8-bits (a bit for the state of each LED), that defines the image to be displayed on the fan.

We keep track of the period of a single rotation with an IR sensor that triggers every time it approaches the stand. Capturing the time between these triggers can allow to know the RPM and accordingly how much time each sector should take up.

These events all happen according to interrupts. The updating of sectors occurs through an update interrupt; making sure every sector takes exactly the same amount of time. A capture interrupt is used to know when the IR sensor triggers.

The ESP32 was programmed using PlatformIO with IoT Development Framework to host the web page, receive input from the user and send it to the Nucleo as an I2C master. 

We set up a web server with a very minimalistic  UI to avoid high power consumption. It can be accessed by typing the IP of the ESP32 on your local network. This will send a GET request that will load the page. The input form sends a POST request to the ESP32, and with some string manipulation, we will have the user message. To improve the performance and reduce the overhead, we implemented this web server using ESP-IDF, not Arduino libraries. 

For the I2C master to work, it uses a command link which is a logical element containing all the actions that are needed to interact with the slave. The link is basically a queue and the commands should be queued to it. I2C master sends queued commands and The task will be blocked until all the commands have been sent out.

To avoid tearing and corruption when updating the currently displayed text, we implemented a double buffer; similar to what is used to implement vertical sync in monitors. Essentially, the text being displayed is being read from 1 array and the text being sent to the Nucleo is being written to a different array. When the transfer is complete, we switch the 2 arrays so that the one with the new text is used to display the image and the array with the old text is used to store the next string being sent.
This effectively eliminated any instance of an array being read from and written to at the same time; this introduces the possibility of having 1 half of a new string displayed while the old half is remaining till the rest of the display is updated.

## Workarounds and challenges

The IR sensor is not quite good. It experiences many false positives; meaning a single approach of the sensor would appear as 6 triggers. We solved this with "debouncing", ignoring periods between triggers that are less than a certain threshold. Trying to use the hall effect didn't work as the locally available sensor's quality is poor and had unsuitable sensitivity.

## Potential feature
- Addressable RGB strip to display color images
- display custom GIFs


## Components

- [DC motor 13k rpm](https://ram-e-shop.com/product/dc-12v-80w-13000rpm-775-motor/) to drive the blade
- [Motor Driver](https://ram-e-shop.com/product/kit-l298-red/) to adjust the speed of the motor
- Stand and Blade (custom fabricated)
- [IR sensor](https://ram-e-shop.com/product/kit-object-ir/) to detect a rotation
- [LEDs](https://ram-e-shop.com/product/led-rr/) as pixels for the display
- Nucleo STM32L432KC to drive the display
- [Arduino uno](https://ram-e-shop.com/product/kit-arduino-uno/) to adjust the speed of the blade motor
- [9v Battery](https://ram-e-shop.com/product/9v-battery-energizer-alkaline/) to power the components on the blade
- [12V battery](https://ram-e-shop.com/product/battery-li-12v-3000mah/) to power the on blade components
- [220Ohms resistors](https://ram-e-shop.com/product/fixed-resistances-44/) to drive the LED
- [ESP32 DevKit](https://ram-e-shop.com/product/kit-esp32-esp32s/) as a webserver

## Refrences 
- [IDF documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)
- [ESP32 I2C master](http://www.lucadentella.it/en/2017/10/09/esp32-23-i2c-basic/)
- [HTTP Requests](https://developer.mozilla.org/en-US/docs/Learn/Forms/Sending_and_retrieving_form_data)
