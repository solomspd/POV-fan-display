#Automatic obstacle avoidance car and rerouting

The main goal of automatic methods is to take a decision with the human interference. The first phase should deliver a system that enables a car to travel from position A to position B in a straight. The two positions will be preprogramed and it will use GPS module to determine the destination and the current location. 
Moreover, a second functionality could be added which will allow the car to detect small obstacles and reroute itself to avoid them then continue to its destination. 
A microcontroller will be used to drive a 4-wheel car to certain direction based on the current location, the direction its heading and the destination. a gyroscope could be used to determine the change in direction made by the car. The compass module will help in determining the original direction of the car and the most important component is the GPS module which will determine the current location. An ultrasonic distance measuring module can be used to detect the small obstacles. 

##Challenges 

Calibrating the gyroscope to get the change in angel may be a hard task especially with the huge relative error in the modules found in Egypt. 
Configuring the GPS on neucleo may also be challenging as we didn’t deal with a GPS before on the embedded level.

##Limitation

the hardest challenge that could face this project is the rerouting problem as it may be harder with harder obstacles, that’s why we decided to only account for small obstacles (that could be avoided by turning left of right then continuing to the destination). 

##components

- Ultrasonic Sensor & Distance Measurement Module HC-SR04
- Main board: neucleo STM32L432K
- IMU MPU6050 "3-Axis Acceleration Gyroscope 6DOF Module" Original
- Module gyroscope + accelerometer + compass
- GR-87 GPS Receiver Module 
