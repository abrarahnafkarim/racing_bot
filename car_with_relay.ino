#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX pins for Bluetooth module
#define relay1Pin 2
#define relay2Pin 3
#define relay3Pin 4
#define relay4Pin 5

void setup() {
  // Set relay pins as output
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
  
  // Set up serial communication with Bluetooth module
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    
    // Control the car based on received commands
    switch(command) {
      case 'F': // Forward
        digitalWrite(relay1Pin, HIGH);
        digitalWrite(relay2Pin, LOW);
        digitalWrite(relay3Pin, HIGH);
        digitalWrite(relay4Pin, LOW);
        break;
      case 'B': // Backward
        digitalWrite(relay1Pin, LOW);
        digitalWrite(relay2Pin, HIGH);
        digitalWrite(relay3Pin, LOW);
        digitalWrite(relay4Pin, HIGH);
        break;
      case 'L': // Left
        digitalWrite(relay1Pin, LOW);
        digitalWrite(relay2Pin, HIGH);
        digitalWrite(relay3Pin, HIGH);
        digitalWrite(relay4Pin, LOW);
        break;
      case 'R': // Right
        digitalWrite(relay1Pin, HIGH);
        digitalWrite(relay2Pin, LOW);
        digitalWrite(relay3Pin, LOW);
        digitalWrite(relay4Pin, HIGH);
        break;
      case 'S': // Stop
        digitalWrite(relay1Pin, LOW);
        digitalWrite(relay2Pin, LOW);
        digitalWrite(relay3Pin, LOW);
        digitalWrite(relay4Pin, LOW);
        break;
      default:
        // Invalid command
        break;
    }
  }
}
