# Automatic obstacle avoidance car and rerouting

The main goal of automatic methods is to take a decision with the human interference. The first phase should deliver a system that enables a car to travel from its current location to a destination in a straight. Through GPS, the destination can be put in by placing the robot in the desired location and pressing a button and it will determine the destination and the current location. 
Moreover, a second functionality could be added which will allow the car to detect small obstacles and reroute itself to avoid them then continue to its destination. 
A microcontroller will be used to drive a 4-wheel car to certain direction based on the current location, the direction its heading and the destination. A gyroscope could be used to determine the change in direction made by the car. The compass module will help in determining the original direction of the car and the most important component is the GPS module which will determine the current location. An ultrasonic distance measuring module can be used to detect the small obstacles. 

## Challenges 

The rerouting algorithm can prove to be difficult to construct, hence we set out to account for simpler obstacles and have the ability to back track and more complicated avoidance be a stretch goal.
Calibrating the gyroscope to get the change in angel may be a hard task especially with the huge relative error in the modules found in Egypt. 
Configuring the GPS on neucleo may also be challenging as we didn’t deal with a GPS before on the embedded level.

## Limitation

The hardware used, naturally, has limited accuracy; especially the GPS being typically accurate to 3 meters. This results in this solution being effective outdoors with limited ability indoors.

## components

- Ultrasonic Sensor & Distance Measurement Module HC-SR04
- Main board: neucleo STM32L432K
- IMU MPU6050 "3-Axis Acceleration Gyroscope 6DOF Module" Original
- compass module
- GR-87 GPS Receiver Module 
- Dagu robot
