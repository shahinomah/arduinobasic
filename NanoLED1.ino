const int ledPin = 11;  // LED connected to pin D9

void setup() {
  pinMode(ledPin, OUTPUT);     // Set LED pin as output
  Serial.begin(9600);          // Start Serial communication
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED on
  Serial.println("LED is ON");
  delay(1000);                 // Wait 1 second

  digitalWrite(ledPin, LOW);   // Turn LED off
  Serial.println("LED is OFF");
  delay(1000);                 // Wait 1 second
}
