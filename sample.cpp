// Define pins for the Ultrasonic Sensor
const int trigPin = 7;
const int echoPin = 6;

// Define pins for LEDs and Buzzer
const int greenLed = 3;
const int yellowLed = 4;
const int redLed = 5;
const int buzzer = 2;

void setup() {
  // Setup pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Start serial communication for monitoring on computer
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by setting it HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters (Speed of sound is 0.034 cm/us)
  int distance = duration * 0.034 / 2;
  
  // Print distance to the Serial Monitor
  Serial.print("Water distance from sensor: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Decision logic based on distance (Lower distance means water is rising closer)
  if (distance > 30 || distance <= 0) {
    // SAFE ZONE: Water level is low
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  } 
  else if (distance <= 30 && distance > 15) {
    // WARNING ZONE: Water level is rising
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
  } 
  else {
    // DANGER ZONE: Flood risk level reached!
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000); // Send sound signal to piezo buzzer
  }
  
  // Short delay before next measurement
  delay(500);
}
