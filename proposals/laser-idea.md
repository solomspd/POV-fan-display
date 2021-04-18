# Configurable laser drawing projector with STM32L4

Among the methods of projecting images onto a wall is laser projection.
Laser projection in itself comes in multiple variations, among them is where you have a single laser source that moves at incredible speed along the XY axis so that it would trick the human eye in thinking there were a continuous drawing on the wall projected on.

Beyond this core functionality, there can be webpage that allows a user to input a certain image to be projected and for it to be correctly processed and drawn on the projection surface.

The device's operation is quite straight forward. It involves having a laser in a fixed position pointing at a set of mirrors set at perpendicular angles. Each mirror is connected to a stepper motor with 1 mirror being responsible for movement in the X axis and the other responsible for movement in the Y axis. Of course this would require a stepper motor controller to operate them. The device should be able to support blanking so that i can display more than 1 "line" and have multiple distinct shapes at a single time.

This is to be connected to another board to host a simple webpage. When this web page receives line art for it draw or even a string of text to draw, it sends it over to the main board through serial communication for it to update the projected image.

## Challenges
A clear challenge in accomplishing this is a mechanical one.
To properly align the mirrors together and ensure their motors are able to move at the required speed with enough accuracy.

Beyond that, it can also prove to be difficult to figure out the proper values to set a stepper motor for it go to the desired location.

## Limitations

The complexity of the images projected are limited by the technology of the motors and the ICs. They can only go so fast. A degree of complexity can happen where you can still see the laser trying to make an image but it no longer blends together into a single coherent image.

Also the web page would not be provided with a regular jpeg image. Instead, it would be provided with either a string of text or a discrete set of line art points that would be more easily easily interpreted into projection form.

## Components required

- 2x stepper motor: https://ram-e-shop.com/product/step-39hz34-610/
- stepper motor controller: https://uge-one.com/tb6560-stepper-motor-driver-3a.html/
- 2x small mirrors
- Main board: neucleo STM32L432K
- Webpage host: esp32 https://ram-e-shop.com/product/kit-esp32-esp32s/