// Pin Definitions
const int ldrPin = A0;      // LDR connected to analog pin A0
const int ledPin = 11;       // LED connected to PWM-capable digital pin D3

int ldrValue = 0;           // Variable to store raw LDR reading
int ledBrightness = 0;      // Variable for LED PWM value (0–255)

// Setup
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

// Function to smooth LDR readings by averaging multiple samples
int readLDR() {
  int sum = 0;
  const int samples = 10;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(ldrPin);
    delay(2);  // Small delay between samples
  }
  return sum / samples;
}

// Main loop
void loop() {
  // Read and smooth LDR value
  ldrValue = readLDR();

  // Map LDR reading (0–1023) to LED brightness (0–255)
  ledBrightness = map(ldrValue, 0, 1023, 0, 255);

  // Update LED brightness
  analogWrite(ledPin, ledBrightness);

  // Print info to Serial Monitor
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" -> LED Brightness: ");
  Serial.println(ledBrightness);

  delay(50);  // Delay to stabilize the output
}
