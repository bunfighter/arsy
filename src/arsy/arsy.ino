/*  Project arsy
 *
 *  Decode the servo signal from the 3rd channel (A and B switch)
 *    of an RC receiver to control a relay.
 *  
 *  Spektrum SLT3 3-Channel SLT Transmitter with SLR300 Receiver
 *  
 *  Project home: https://github.com/bunfighter/arsy/
 *  
 *  Servo library: https://github.com/dmadison/ServoInput/
 *  
 *  Connect servo signal to nano digital pin 2
 *  Connect servo ground to nano ground
 *  Connect servo VCC to nano VIN
 *  Connect the relay control circuit to digital pin 4
 */
 
#include <ServoInput.h>

// Define the servo
ServoInputPin<2> servo;

// Turn the serial debug off or on.
const boolean debug = false;

// Relay control pin
const int relayPin = 4;

// Store the servo angle from the receiver
float recRead = 0;

void setup() {
  if (debug) Serial.begin(115200);
  if (debug) Serial.println("processing Setup");
  
  // Set up the relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  // Set up the LED indicator
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // Get a reading from the receiver (angle of servo: 0 - 180)
  recRead = servo.getAngle();

  // Should we turn the motor off?
  if (recRead > 130) {
    // Yes - turn it off immediately!
    digitalWrite(relayPin, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    if (debug) Serial.println("Relay off");
    
  } else if (recRead > 10 && recRead < 50) {
    // Don't turn the motor on until the button is held for 2 seconds
    unsigned long startTime = millis();
    do {
      if (millis() > startTime + 2000) {
        // button held for 2 seconds. Engine on!
        digitalWrite(relayPin, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        if (debug) Serial.println("Relay on");
        break;
      }
      // Get the next reading
      recRead = servo.getAngle();
    } while (recRead > 10 && recRead < 50);
    
  }
}
