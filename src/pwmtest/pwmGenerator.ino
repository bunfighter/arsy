/*  Project arsy
*
*   Create a pwm signal to test arsy
*
*   Connect a momentary swith between digital pin 4 and GND - ON (A)
*   Connect a momentary swith between digital pin 5 and GND - OFF (B)
*   Connect digital pin 9 to the sensor pin (digital pin 2) on the nano running arsy.
*   press and hold the on button for 2 seconds to turn on the relay
*   press the off button to immediately turn off the relay
*/

#include <Servo.h>

Servo myServo;
const int buttonOnPin = 4;
const int buttonOffPin = 5;
int myAngle = 0;
unsigned long offTime = 0;

void setup() {
  Serial.begin(115200);
  
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(buttonOnPin, INPUT_PULLUP);
  pinMode(buttonOffPin, INPUT_PULLUP);
  offTime = millis();
}
void loop() {
  // Pretend to turn the car on after 3 seconds
  if (millis() > offTime + 3000) {
    myAngle = 90;
  }
  
  if (!digitalRead(buttonOnPin)) {
    // Turn on the motor
    myAngle = 60;
  }

  if (!digitalRead(buttonOffPin)) {
    // Turn on the motor
    myAngle = 150;
  }

  // Control the servo
  Serial.println(myAngle);
  myServo.write(myAngle);
  
}
