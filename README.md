# Line-Follower
!(media/photo.jpg)
A simple line follower robot built using an ESP32 and infrared sensors. The robot detects and follows a line on the ground using basic control logic.
# Features
Line detection using IR sensor array
Real-time motor control
Adjustable behavior through code (thresholds, speed, etc.)
# Hardware
ESP32
IR sensor array (line tracking)
Motor driver (e.g. L298N)
DC motors + wheels
Power supply (battery)
# How it works
The IR sensors read the contrast between the line and the surface. Based on the sensor values, the ESP32 adjusts the motors to keep the robot centered on the line.
# Setup
Connect the components according to your wiring
Upload the code to the ESP32
Place the robot on a track and power it on
# Notes
Sensor calibration is important for good performance
You can improve tracking using PID control