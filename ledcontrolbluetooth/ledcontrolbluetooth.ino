#include "BluetoothSerial.h"

// Define the pin for the built-in LED
const int ledPin = 2;

// Create a BluetoothSerial object
BluetoothSerial SerialBT;

void setup() {
  // Initialize the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize Bluetooth communication with a custom name
  SerialBT.begin("ESP32_LED_Blink");
  Serial.begin(115200);

  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  // Check if there is any available data from Bluetooth
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(incomingChar);

    // Command to turn the LED on and off
    if (incomingChar == 'b' || incomingChar == 'B') {
      digitalWrite(ledPin, HIGH);  // Turn the LED on
      delay(1000);                  // Wait for 0.5 seconds
      digitalWrite(ledPin, LOW);   // Turn the LED off
      delay(500);                  // Wait for 0.5 seconds
      SerialBT.println("LED is blinking");
    }
  }
}
