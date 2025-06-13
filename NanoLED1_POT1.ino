const int potPin = A1;     // Potentiometer connected to analog pin A1
const int ledPin = 3;      // LED connected to PWM pin D9
int potValue = 0;          // Variable to store the potentiometer reading
int ledBrightness = 0;     // Variable to store calculated brightness (0–255)
float resistance = 0.0;    // Variable to store calculated resistance

const float potMaxResistance = 10000.0;  // 10K ohms

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);      // Start Serial communication
}

void loop() {
  // Read analog value from potentiometer (0–1023)
  potValue = analogRead(potPin);

  // Map it to PWM range (0–255)
  ledBrightness = map(potValue, 0, 1023, 0, 255);

  // Estimate resistance based on analog value
  resistance = (potValue / 1023.0) * potMaxResistance;

  // Set LED brightness
  analogWrite(ledPin, ledBrightness);

  // Serial output
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Resistance: ");
  Serial.print(resistance, 1);  // One decimal place
  Serial.print(" ohms");
  Serial.print(" -> LED Brightness: ");
  Serial.println(ledBrightness);

  delay(100); // Small delay for stability
}
