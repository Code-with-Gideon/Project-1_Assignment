// Pins
const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 3;
const int redLED = 4;
const int buzzer = 5;

// Threshold for parking (cm)
const int thresholdDistance = 50; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Fire ultrasonic pulse
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read echo time
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm
  distance = (duration / 2) / 29.1; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Occupancy Logic
  if (distance > 0 && distance <= thresholdDistance) {
    // Car is in the space (within threshold)
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);
  } else {
    // Space is empty
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);
  }
  
  delay(500);
}