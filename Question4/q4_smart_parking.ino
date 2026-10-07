// Pins matching Tinkercad wiring
const int pingPin = 7;   // Purple wire
const int buzzerPin = 6; // Light Blue wire
const int greenLED = 5;  // Orange wire
const int redLED = 4;    // Yellow wire

const int thresholdDistance = 50; // cm

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // The PING))) sensor is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // Convert the time into a distance
  distance = duration / 29.1 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Occupancy Logic
  if (distance > 0 && distance <= thresholdDistance) {
    // Car is in the space
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Space is empty
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzerPin, LOW);
  }
  
  delay(500);
}
