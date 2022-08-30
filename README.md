# arsy
Using an Arduino Nano to decode the servo signal from the 3rd channel (A and B switch) of an RC receiver to control a 24V 40A relay.

Created for a Spektrum SLT3 3-Channel SLT Transmitter with SLR300 Receiver.

This assumes that the the A+B switch on the SLT3 has the factory default settings. You can find code in the servo library for reading the PWM coming from the SLR300 receiver.

Position A on the SLT3 needs to be held for 2 seconds to turn the relay on (safety mkay).
Position B on the SLT3 turns off the relay immediately.

Servo library: https://github.com/dmadison/ServoInput/

## Hardware
- Arduino nano
- Spektrum SLT3 3-Channel SLT Transmitter with SLR300 Receiver
- 18V power tool battery
- 1k 1/4W resistor
- 2N3904 (or similar) PNP transistor
- 1N4007 diode
- 1100-0551 (or similar) power relay
## Nano connections
- Connect servo signal to nano digital pin 2
- Connect servo VCC to nano VIN
- Connect servo ground to nano ground
- Connect 18V Battery ground to nano ground
- Connect thenano digital pin 4 to the relay control circuit

## Relay control circuit diagram
![circuit diagram 1](circuitDiagram.png)
