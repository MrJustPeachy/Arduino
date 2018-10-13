const int trigPin = 10;
const int echoPin = 13;
const int speakerPin = 6;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  if (distance < 30)
  {
    tone(speakerPin, distance);  
  }
  else
  {
    tone(speakerPin, 0);  
  }

  Serial.print("Distance: ");
Serial.println(distance);
}
