
# Configurable laser drawing projector with STM32L4
## Idea:
Laser applications have become omnipresent. These applications vary from kids’ toys to laser cutter. One of those applications is drawing with a laser beam on a surface. 

## Motivation:
A single laser projector can be more efficient compared to traditional projectors when drawing line art
Can be much smaller than traditional projectors
Can create visually appealing results
This application is not very common as an undergraduate project.

## Overview:
Among the methods of projecting images onto a wall is laser projection. Laser projection in itself comes in multiple variations, among them is where you have a single laser source that moves at incredible speed along the XY axis so that it would trick the human eye into thinking there was a continuous drawing on the wall projected on.
The device's operation is quite straightforward. It involves having a laser in a fixed position pointing and a set of mirrors set at perpendicular angles. Each mirror is connected to a stepper motor with 1 mirror being responsible for movement in the X-axis and the other responsible for movement in the Y-axis. Of course this would require a stepper motor driver to operate them. The device should be able to support blanking so that it can display more than 1 "line" and have multiple distinct shapes at a single time.
This is to be connected to another board to host a simple webpage. When this web page receives line art for its draw or even a string of text to draw, it sends it over to the main board through serial communication for it to update the projected image.
Challenges
A clear challenge in accomplishing this is a mechanical one. To properly align the mirrors together and ensure their motors are able to move at the required speed with decent accuracy to produce the desired shape.
Beyond that, it can also prove to be difficult to figure out the proper values to set the  two stepper motors for them to synchronously together properly and produce the desired shape.
To produce an animation would involve difficulties with how quick the changes can be processed and sent from the web page to the neucleo.
Limitations
The complexity of the images projected are limited by the technology of the motors and the ICs. They can only go so fast. Since the eye cannot be deceived if the speed of the laser is less than 25 frames per second, the laser has to go over every single point at least 25 times per second which will introduce a degree of complexity as the eye may still see the laser trying to make an image but because it is not fast enough the shapes won’t blends together into a single coherent image. 
Also the web page would not be provided with a regular jpeg image. Instead, it would be provided with either a string of text to be projected or a discrete line art points from perhaps a grid matrix that would be more easily interpreted into projection form.
The user could also be presented with a 100x100 matrix and advised to choose the vertices of the shape on it.
