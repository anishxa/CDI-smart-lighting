// Pin connections
const int pirPin = 2;  // PIR sensor output pin
const int ldrPin = A0; // LDR analog input pin
const int ledPin = 3;  // LED output pin

// Threshold values
const int ldrThreshold = 500;   // LDR threshold value for night time

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);    // Ensure LED is initially off
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);    // Read LDR value

  // Check if it's nighttime (LDR value below threshold)
  if (ldrValue < ldrThreshold) {
    if (digitalRead(pirPin) == HIGH) {  // PIR detects motion
      digitalWrite(ledPin, HIGH);       // Turn on LED
      Serial.println("Motion detected");
    } else {
      digitalWrite(ledPin, LOW);        // Turn off LED
    }
  } else {
    digitalWrite(ledPin, LOW);          // Turn off LED during daytime
  }
}
