const int analogPin = A0, digitalPin = 7;

void setup() {
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);

  Serial.begin(9600);
}

void loop ()
{

  float Analog;
  int Digital;

  // Current value will be read and converted to the voltage
  Analog = analogRead (analogPin) * (5.0 / 1023.0);
  Digital = digitalRead (digitalPin);

  // and outputted here
  Serial.print ("Analog voltage value:"); Serial.print (Analog, 4);  Serial.print ("V, ");
  Serial.print ("Extreme value:");

  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not reached yet");
  }

  Serial.println ("----------------------------------------------------------------");

  delay (200);

}
