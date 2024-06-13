# Vehicle-Control-System
1. The system displays the main menu
a. Turn on the vehicle engine
b. Turn off the vehicle engine
c. Quit the system

2. If chose to “Quit the system”: Quit program

3. If chose to “Turn off the vehicle engine”: system displays the main menu

4. If chose to “Turn on the vehicle engine”: system displays “sensors set menu”, menu that simulates the vehicle sensors readings.
a. Turn off the engine
b. Set the traffic light color.
c. Set the room temperature (Temperature Sensor)
d. Set the engine temperature (Engine Temperature Sensor)

a. Based on traffic light data
i. If the traffic light is ‘G’ set vehicle speed to 100 km/hr
ii. If the traffic light is ‘O’ set vehicle speed to 30 km/hr
iii. If the traffic light is ‘R’ set vehicle speed to 0 km/h

b. Based on room temperature data (Take it as input from console, we will assume that this is the sensor read value)
i. If temperature less than 10, Turn AC ON and set temperature to 20
ii. If temperature is greater than 30, Turn AC ON and set temperature to 20
iii. If temperature is otherwise, Turn AC OFF

c. Based on engine temperature data
i. If temperature less than 100, Turn “Engine Temperature Controller” ON and set temperature to 125
ii. If temperature is greater than 150, Turn “Engine Temperature Controller” ON and set temperature to 125
iii. If temperature is otherwise, Turn “Engine Temperature Controller” OFF

d. If vehicle speed is 30 km/hr
i. Turn ON AC if it was OFF and set room temperature to: current temperature * (5/4) + 1
ii. Turn ON “Engine Temperature Controller” if it was OFF and set engine temperature to: current temperature * (5/4) + 1

e. Display the current vehicle state
i. Engine state: ON/OFF.
ii. AC: ON/OFF.
iii. Vehicle Speed.
iv. Room Temperature.
v. Engine Temperature Controller State.
vi. Engine Temperature.

