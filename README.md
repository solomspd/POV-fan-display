# Persistance of Vision Fan Display
A novel approach to creating images is through a Persistance Of Vision (POV) fan display.

Essentially, it is a fixture of a platform mounted on a motor that spins at high speeds so that you can no longer see the individual LED lights.
Then, the LEDs would light up at certain intervals so that it seems to the human eye that there is 1 cohesive image.

Beyond this base functionality, there can be a webpage that allows a user to input a string of text or perhaps even an image that will be correctly processed and displayed on the POV display.

This display can have the ability to not only display text, including a digital clock, but also any art such as an analogue clock.

The display should also be able to support any speed of rotation and be able to cope with dynamically changing it.

## Design
All logic will be placed inside the rotating blade itself so that we do not need to worry about power delivery to the MCU controller and for them to have their own independent battery rotating with them.
So within the blade would be the LED strip, the Nucleo MCU and the ESP32 MCU.
The Nucleo MCU will be the heart of the system, is directly connected to both the strip and an IR sensor.
The IR sensor is needed since we are using a dumb DC motor to drive the blade so there is no way of knowing the RPM of the motor.
To resolve this, we use an IR sensor to keep track of how much time a single revolution takes.

The ESP32 MCU is there so that it can communicate with the Nucleo, updating it with new visuals requested by the user.
The ESP32 will also serve the front end to the user in the form of a webpage where they can enter new text or graphics.

Beyond the blade, the DC motor is operates using a motor driver so that we can control its speed.
This speed control is carried out very simply with an Arduino that is only there to supply the motor driver with a PWM signal so we can dynamically change the speed of the motor.

![architecture of system](https://github.com/solomspd/Embedded-Project-2/blob/master/proposals/schematic.png)

## Challenges
- A clear challenge in accomplishing this is a mechanical one; getting the hardware physically configured correctly and ensuring stability at high speeds.
- Synchronizing the display with the period of a single revolution of the motor so the image can appear to stay in place.
- MCU will be rotating with the LEDs so it will be d

## Limitations
- Distortion will be induced in any image that we attempt to display. This distortion is due to the fact that the LEDs are of different distances from the centre of the rotating circle. So, LEDs that are far from the centre will have a bigger arc to move within. For example, when displaying the letter E, the upper edge will look wider than the lower ones.

- The length and resolution of messages capable of being displayed. We can update the LEDs only as fast as the MCU allows and remains readable. Thus, we can allow only a specific number of letters based time each letter takes to display. The resolution of a character is limited according to the number of LEDs on the rotating edge.


## Components

- [DC motor 13k rpm](https://ram-e-shop.com/product/dc-12v-80w-13000rpm-775-motor/)
- [Motor Driver](https://ram-e-shop.com/product/kit-l298-red/)
- Stand and Blade (custom fabricated)
- [IR sensor](https://ram-e-shop.com/product/kit-object-ir/)
- [LEDs](https://ram-e-shop.com/product/led-rr/)
- Nucleo STM32L432KC
- [Arduino uno](https://ram-e-shop.com/product/kit-arduino-uno/)
- [9v Battery](https://ram-e-shop.com/product/9v-battery-energizer-alkaline/)
- [12V battery](https://ram-e-shop.com/product/battery-li-12v-3000mah/)
- [220Ohms resistors](https://ram-e-shop.com/product/fixed-resistances-44/)
- [ESP32 DevKit](https://ram-e-shop.com/product/kit-esp32-esp32s/)
