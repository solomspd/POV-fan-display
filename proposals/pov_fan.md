# Persistance of vision fan display
A novel approach to creating images is through a Persistance Of Vision (POV) fan display.

Essentially, it is a fixture of a platform mounted on a motor that spins at high speeds so that you can no longer see the individual LED lights.
Then, the LEDs would light up at certain intervals so that it fools the human eye into thinking there is 1 cohesive image.

Beyond this base functionality, there can be a webpage that allows a user to input a string of text or perhaps even an image that will be correctly processed and displayed on the POV display.

## Design

## Challenges
- A clear challenge in accomplishing this is a mechanical one.
- As planned we are going to allow for different options for the display. For example, we are going to display both analog and digital clocks. The analog clock will represent a challenge because we have to synchronize the time and seconds hand with our POV display

## Limitations
- A clear limitation would be handeling the images or even letters because we have distortion. This distortion due to the fact that the leds are of different distances from the center. So, leds that are far from the center will have a bigger arc to move within. For example when displaying the letter E, the upper edge will look taller than the lower ones.

- Another limitation is that we don't have the capacity to display a very tall message. We only have 360 sectors (based on 360 degrees of a circle). Thus, we can allow only a specific number of letters based on the number of sectors each letter take. Moreover, the longer the message, the less the rotation of each letter.


## Components

- DC motor 13k rpm (You don't need that much arround 1k is acceptable)
- Motor Driver
- Fan blade
- Mount and Base (3D printed)
- IR sensor
- 5mm LEDs
- STM32 board
- 9v Battery
- Power Supply/ or 12V battery to drive the motor
- 200Ohms resistors. (100-400) is an acceptable range
- Esp32 board