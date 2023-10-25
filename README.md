# Vision-Aid
Title of Project (Initial): Traffic Clearance System for Emergency Vehicles Using Machine Learning
Team Name: Algorithm Avengers

The growing number of vehicles on road creates many problems such as traffic congestion which hinders the movement of Emergency Vehicles such as Ambulance, Police Vehicle, Fire Brigades, etc. Our solution aims at manipulating the Traffic Light System, present at the intersections, according to the direction of the approaching Emergency Vehicle (Ambulance, for the scope of this project) using Machine Learning.

Use Cases

The machine vision camera detects the Ambulance and sends a message with the help of ESP32 module to the Traffic Lights System’s ESP32 module to establish communication between them.
The direction of the Emergency Vehicle will be provided with the help of the IP/Network camera number that shares the trigger.
The traffic signal lights for the moving traffic lane is made to turn yellow with the help of Relay devices installed in the traffic controller
A buffer road-clearance timing ranging between 3-5 secs according to the real-world calculation would be provided. This is also known as Early Cutoff.
The inductive loop detectors/sensors allow the traffic signal for the Emergency Vehicle to change to Green as soon as the road intersection is clear.
This allows in preventing any collisions or accidents due to sudden rush.
The Ambulance movement is monitored with the help of the ANPR Camera that uses the registered vehicle record in the RTO/Police database.
After the successful movement of the Ambulance, the traffic signals reset to the default time cycle for the junction. This can be determined according to the crowd density or through the serial order.
