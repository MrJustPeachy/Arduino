// Import modules
#include <stdlib.h>
#include <string.h>

// Setup vars
const int firstLED = 2, secondLED = 3, thirdLED = 4, fourthLED = 5, fifthLED = 6, sixthLED = 7, seventhLED = 8, eighthLED = 9, tapPin = 13;
int counter = 0;
char buffer [9];

void setup() {
  // Set the tap module to input
  pinMode(tapPin, INPUT);

  // Set all of the led pins to output
  for (int i = 2; i < 10; i++)
    pinMode(i, OUTPUT);

  // Log info to port 9600
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // reset buttonPress to 0
  int buttonPress = digitalRead(tapPin);

  // If button is pressed (default is HIGH), then increment the counter (which is the amount of taps)
  if (buttonPress == LOW)
    counter++;

  // Convert buffer to binary
  itoa(counter, buffer, 2);

  // Print out the decimal and binary numbers
  Serial.println(counter);
  Serial.println(buffer);

  // Setup tracker for setting each LED
  int tracker = 1;

  // Go through binary number backwards to they display on LEDs correctly
  for (int i = strlen(buffer); i >= 0; i--)
  {
    // If it's 1, light the LED
    if (buffer[i] == '1')
      digitalWrite(tracker, HIGH);
    // Else if it's 0,turn the LED off
    else if (buffer[i] == '0')
      digitalWrite(tracker, LOW);
    // Increment tracker, so it writes to the correct LED pin
    tracker++;
  }
  // Delay each loop by 1/4 of a second, so it doesn't add too fast
  delay(250);
}
