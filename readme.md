### DRM

Welcome to the Dynamic Robotic Manipulator (DRM) :)
----------------------------------------------------
Credits:
Lead Dev + Building + Code:
Linkjt9 (John Falciglia)

Acknoledgements:
Thx to everybody that helped with this jouerny, Saatvik, Tsz-Cheun, and the WPCPXC team
In addition, I would like to thank the entrie Cemetech Community :)

Nerd Stuff (If your just looking for Fun Stuff or smth, skip to ____):
System: Arduino UNO R3
Language: C++
Packages/Libraries Used: Wire.h, Adafruit_Sensor.h, and Adafruit_ADXL345_U.h
Eletric Parts Required: 
- 28BYJ-48 Stepper Motor
- 28BYJ-48 Stepepr Motor Driver
- ADXL 345 Accelerometer
- Arduino UNO R3 Expansion Board
Pins Used:
- 4 GND Pins
- 4 5V Pins
- Analog Pins 2,3,4,5,6,7,8,9,10,11,12,13
- Input Pins A4, A5

Varibles:
*Independent:
- degreeturn; determains the amount of tilt on the accelerometer for the microcontoller to regocnize and produce motor movement
- rpm; the amount of delay between each motor signal, lower will make the motors spin faster, but they are also harder to control
