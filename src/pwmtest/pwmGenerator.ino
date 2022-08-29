// UNO
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
