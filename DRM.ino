/* Things for the accelerometer */
#include <Wire.h>

#include <Adafruit_Sensor.h> 

#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
/*Set up all Pin Definitions */
#define BSTEPPER_PIN_1 13
#define BSTEPPER_PIN_2 2
#define BSTEPPER_PIN_3 3
#define BSTEPPER_PIN_4 4
#define ASTEPPER_PIN_1 5
#define ASTEPPER_PIN_2 6
#define ASTEPPER_PIN_3 7
#define ASTEPPER_PIN_4 8
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
int step_number = 0;
int astep_number = 0;
int bstep_number = 0;
/*Altercating degreeturn results in a change in the angle of the hand required to produce movment
Smaler values means it will pick up more, but it means that it can also pick up more interference
large values require more tilt, but are generally more reliable */
int degreeturn = 2.5;
/*The inverse of how fast the arm should spin, 
smaller values means that the arm's motors spin faster, bigger values mean the arm spins slower */
int rpm = 10;
/*Setup the pins as output */
void setup() {
/* Make Sure the Accelraometer is there */
Serial.begin(9600);  

   if(!accel.begin())

   {

      Serial.println("No valid sensor found");


   }
/*Setup the pins as output */
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(ASTEPPER_PIN_1, OUTPUT);
pinMode(ASTEPPER_PIN_2, OUTPUT);
pinMode(ASTEPPER_PIN_3, OUTPUT);
pinMode(ASTEPPER_PIN_4, OUTPUT);
pinMode(BSTEPPER_PIN_1, OUTPUT);
pinMode(BSTEPPER_PIN_2, OUTPUT);
pinMode(BSTEPPER_PIN_3, OUTPUT);
pinMode(BSTEPPER_PIN_4, OUTPUT);

}

void loop() {
 /*Turn one Degree Clockwise on the arm and A degree on the Hand counterclockwise*/

  sensors_event_t event; 

   accel.getEvent(&event);


   if(-degreeturn > event.acceleration.x){
    Basedegree(true);
    delay(rpm);
   }
   
   if(-degreeturn > event.acceleration.y){
    Armdegree(true);
    delay(rpm);
   } 
   if(degreeturn < event.acceleration.x){
    Basedegree(false);
    delay(rpm);
   }
   if(degreeturn < event.acceleration.y){
    Armdegree(false);
    delay(rpm);
   } 

}

/* Motor charge aliments to turn the motor, Same with Arm and Base degree */
void Handdegree(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
void Armdegree(bool dir){
    if(dir){
switch(astep_number){
  case 0:
  digitalWrite(ASTEPPER_PIN_1, HIGH);
  digitalWrite(ASTEPPER_PIN_2, LOW);
  digitalWrite(ASTEPPER_PIN_3, LOW);
  digitalWrite(ASTEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(ASTEPPER_PIN_1, LOW);
  digitalWrite(ASTEPPER_PIN_2, HIGH);
  digitalWrite(ASTEPPER_PIN_3, LOW);
  digitalWrite(ASTEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(ASTEPPER_PIN_1, LOW);
  digitalWrite(ASTEPPER_PIN_2, LOW);
  digitalWrite(ASTEPPER_PIN_3, HIGH);
  digitalWrite(ASTEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(ASTEPPER_PIN_1, LOW);
  digitalWrite(ASTEPPER_PIN_2, LOW);
  digitalWrite(ASTEPPER_PIN_3, LOW);
  digitalWrite(ASTEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(astep_number){
  case 0:
  digitalWrite(ASTEPPER_PIN_1, LOW);
  digitalWrite(ASTEPPER_PIN_2, LOW);
  digitalWrite(ASTEPPER_PIN_3, LOW);
  digitalWrite(ASTEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(ASTEPPER_PIN_1, LOW);
  digitalWrite(ASTEPPER_PIN_2, LOW);
  digitalWrite(ASTEPPER_PIN_3, HIGH);
  digitalWrite(ASTEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(ASTEPPER_PIN_1, LOW);
  digitalWrite(ASTEPPER_PIN_2, HIGH);
  digitalWrite(ASTEPPER_PIN_3, LOW);
  digitalWrite(ASTEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(ASTEPPER_PIN_1, HIGH);
  digitalWrite(ASTEPPER_PIN_2, LOW);
  digitalWrite(ASTEPPER_PIN_3, LOW);
  digitalWrite(ASTEPPER_PIN_4, LOW);
 
  
} 
  }
astep_number++;
  if(astep_number > 3){
    astep_number = 0;
  }
}
void Basedegree(bool dir){
    if(dir){
switch(bstep_number){
  case 0:
  digitalWrite(BSTEPPER_PIN_1, HIGH);
  digitalWrite(BSTEPPER_PIN_2, LOW);
  digitalWrite(BSTEPPER_PIN_3, LOW);
  digitalWrite(BSTEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(BSTEPPER_PIN_1, LOW);
  digitalWrite(BSTEPPER_PIN_2, HIGH);
  digitalWrite(BSTEPPER_PIN_3, LOW);
  digitalWrite(BSTEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(BSTEPPER_PIN_1, LOW);
  digitalWrite(BSTEPPER_PIN_2, LOW);
  digitalWrite(BSTEPPER_PIN_3, HIGH);
  digitalWrite(BSTEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(BSTEPPER_PIN_1, LOW);
  digitalWrite(BSTEPPER_PIN_2, LOW);
  digitalWrite(BSTEPPER_PIN_3, LOW);
  digitalWrite(BSTEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(bstep_number){
  case 0:
  digitalWrite(BSTEPPER_PIN_1, LOW);
  digitalWrite(BSTEPPER_PIN_2, LOW);
  digitalWrite(BSTEPPER_PIN_3, LOW);
  digitalWrite(BSTEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(BSTEPPER_PIN_1, LOW);
  digitalWrite(BSTEPPER_PIN_2, LOW);
  digitalWrite(BSTEPPER_PIN_3, HIGH);
  digitalWrite(BSTEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(BSTEPPER_PIN_1, LOW);
  digitalWrite(BSTEPPER_PIN_2, HIGH);
  digitalWrite(BSTEPPER_PIN_3, LOW);
  digitalWrite(BSTEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(BSTEPPER_PIN_1, HIGH);
  digitalWrite(BSTEPPER_PIN_2, LOW);
  digitalWrite(BSTEPPER_PIN_3, LOW);
  digitalWrite(BSTEPPER_PIN_4, LOW);
 
  
} 
  }
bstep_number++;
  if(bstep_number > 3){
    bstep_number = 0;
  }
}