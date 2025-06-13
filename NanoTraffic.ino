const int ledRed = 8;
const int ledYellow = 7;
const int ledGreen = 6;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // GREEN light
  digitalWrite(ledGreen, HIGH);
  Serial.println("GO >>>");
  delay(2000);
  digitalWrite(ledGreen, LOW);
  delay(500);

  // YELLOW light
  digitalWrite(ledYellow, HIGH);
  Serial.println("SLOW DOWN");
  delay(2000);
  digitalWrite(ledYellow, LOW);
  delay(500);

  // RED light
  digitalWrite(ledRed, HIGH);
  Serial.println("STOP !!!");
  delay(2000);
  digitalWrite(ledRed, LOW);
  delay(500);  // Short delay before restarting the cycle
  Serial.println("");
}
