int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
int greenPin = 4;
int yellowPin1 = 5;
int yellowPin2 = 6;
int redPin = 7;
long duration, cm;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin1,OUTPUT);
  pinMode(yellowPin2,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(greenPin,HIGH);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
 
  if(cm <= 14 and cm >= 10)
     {digitalWrite(yellowPin1, HIGH);
      delay(250);
      digitalWrite(yellowPin1, LOW);
     }
if(cm <= 9 and cm >= 6)
     {digitalWrite(yellowPin1, HIGH);
     digitalWrite(yellowPin2, HIGH);
      delay(150);
      digitalWrite(yellowPin1, LOW);
      digitalWrite(yellowPin2, LOW);
     }
     if(cm <= 5)
     {digitalWrite(yellowPin1, HIGH);
     digitalWrite(yellowPin2, HIGH);
     digitalWrite(redPin, HIGH);
      delay(50);
      digitalWrite(yellowPin1, LOW);
      digitalWrite(yellowPin2, LOW);
      digitalWrite(redPin, LOW);
     }

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}