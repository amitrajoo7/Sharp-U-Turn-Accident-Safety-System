// Pin definitions
const int irSensor1 = D1;
const int irSensor2 = D2;
const int irSensor3 = D3;
const int irSensor4 = D4;

const int redLed1 = D0;
const int redLed2 = D7;
const int yellowLed1 = D6;
const int yellowLed2 = D5;
const int greenLed1 = D8;  // First green LED
const int greenLed2 = 3; // Second green LED output S3

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize IR sensor pins
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);  
  pinMode(irSensor4, INPUT);

  // Initialize LED pins
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(yellowLed1, OUTPUT);
  pinMode(yellowLed2, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  pinMode(greenLed2, OUTPUT);

  // Turn on all green LEDs initially
  digitalWrite(greenLed1, HIGH);
  digitalWrite(greenLed2, HIGH);
}

void loop() {
  // Read the IR sensor values
  int ir1State = digitalRead(irSensor1);
  int ir2State = digitalRead(irSensor2);
  int ir3State = digitalRead(irSensor3);
  int ir4State = digitalRead(irSensor4);

  // Control LEDs based on IR sensor states
  if (ir1State == LOW) { // First IR sensor detects object
    digitalWrite(redLed2, HIGH);
    digitalWrite(greenLed2, LOW);
  } else if (ir2State == LOW) { // Second IR sensor detects object
    digitalWrite(yellowLed2, HIGH);
    digitalWrite(greenLed2, LOW);
  } else if (ir3State == LOW) { // Third IR sensor detects object
    digitalWrite(redLed1, HIGH);
    digitalWrite(greenLed1, LOW);
  } else if (ir4State == LOW) { // Fourth IR sensor detects object
    digitalWrite(yellowLed1, HIGH);
    digitalWrite(greenLed1, LOW);
  } else { // No IR sensor detects object
    digitalWrite(greenLed1, HIGH);
    digitalWrite(greenLed2, HIGH);

    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(yellowLed1, LOW);
    digitalWrite(yellowLed2, LOW);
  }
}
