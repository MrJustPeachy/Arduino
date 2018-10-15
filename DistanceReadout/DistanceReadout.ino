#include <LiquidCrystal.h>

// Declare and initialize vars / pin locations
const int trigPin = 2;
const int echoPin = 3;
const int rs = 7, rw = 9, enable = 8, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
long duration, inches;
int distance;
char distanceStr;
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

void setup() {
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set serial port (for printing out to console)
  Serial.begin(9600);

  // Initialize LCD screen to have 16 columns and 2 rows
  lcd.begin(16, 2);
  lcd.print("Hello World");
}

void loop() {
  // This sends out an ultrasonic signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // This gets how long it takes for the echo of the signal to return
  duration = pulseIn(echoPin, HIGH);

  // This converts the duration into inches
  distance = (duration / 2) / 74;

  // Prints out the distance to the console
  Serial.print("Distance: ");
  Serial.println(distance);

  // Clear the LCD screen and then print out the distance
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(distance);

  // Wait 1/4 of a second before running through the loop again
  delay(250);
}
