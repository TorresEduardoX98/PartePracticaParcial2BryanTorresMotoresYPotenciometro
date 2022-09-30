#include <Stepper.h>
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int stepCount = 0;  // numero de pasos el motor a dado
 
void setup() {
Serial.begin(9600);
}
 
void loop() {
// Lee el valor del sensor:
int sensorReading = analogRead(A0);
int motorSpeed = map(sensorReading, 0, 1023, 0, 20);
Serial.println(motorSpeed);
if (motorSpeed > 0) {
myStepper.setSpeed(motorSpeed);
myStepper.step(stepsPerRevolution / 1000);
}
}
