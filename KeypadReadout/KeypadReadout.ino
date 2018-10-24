#include <Keypad.h>
#include <string.h>

// Thanks to the keypad library for template code: https://playground.arduino.cc/code/keypad
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {7, 8, 9, 10};
byte colPins[COLS] = {11, 12, 13};
const int firstLED = 2, secondLED = 3, thirdLED = 4, fourthLED = 5, fifthLED = 6;
int total = 0;
int keyPress = 0;
char buffer[6];

// Initialize keypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {

  // Set all of the led pins to output
  for (int i = 2; i < 8; i++)
    pinMode(i, OUTPUT);

  // Setup port for console output
  Serial.begin(9600);    
}

void loop() {
  // get the keypress
  char key = myKeypad.getKey();

  // Don't compute if no key, asterisk key, pound key, or 0 is pressed
  if (key != NO_KEY && key != '#' && key != '*' && key != '0'){

    // Add the key number (subtracts 0 char to convert number char to int)
    total += key - '0';

    // Convert total to binary char buffer
    itoa(total, buffer, 2);

    // Setup tracker for LED output
    int tracker = 1;
    
    // Go through binary number backwards to they display on LEDs correctly
    for (int i = strlen(buffer); i >= 0; i--)
    {
      // If it's 1, light the LED
      if (buffer[i] == '1')
        digitalWrite(tracker, HIGH);
      // Else if it's 0,turn the LED off
      else
        digitalWrite(tracker, LOW);
      // Increment tracker, so it writes to the correct LED pin
      tracker++;
    }
    // Delay each loop by 1/4 of a second, so it doesn't add too fast
    delay(250);
    
  }
}
