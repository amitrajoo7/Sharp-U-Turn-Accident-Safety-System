#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(D2, D3, D4, D5, D6, D7);  // RS, EN, D4, D5, D6, D7

const int trigPin = D1; // Trig pin of the ultrasonic sensor
const int echoPin = D0; // Echo pin of the ultrasonic sensor

float distance = 0.0;
float previousDistance = 0.0;
float speed = 0.0;
unsigned long previousTime = 0;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Convert to centimeters

  // Calculate the speed
  unsigned long currentTime = millis();
  if (previousTime > 0) {
    float timeDifference = (currentTime - previousTime) / 1000.0; // Convert to seconds
    speed = (distance - previousDistance) / timeDifference; // Calculate speed in cm/s
  }
  
  // Update previous values
  previousDistance = distance;
  previousTime = currentTime;

  // Clear the previous values from the LCD
  lcd.clear();

  // Print the distance to the first row
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Print the speed to the second row
  lcd.setCursor(0, 1);
  lcd.print("Speed: ");
  lcd.print(speed);
  lcd.print(" cm/s");

  // Add a delay for demonstration purposes
  delay(1000); // Wait for 1 second
}
