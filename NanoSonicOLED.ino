#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED parameters
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C  // Change to 0x7A if your OLED has that address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;
long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("OLED initialization failed"));
    while (true); // Halt if OLED fails
  }

  display.clearDisplay();
  display.setTextSize(1);       // Normal text size
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Ultrasonic Sensor");
  display.display();
  delay(1000);
}

void loop() {
  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Serial output
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // OLED display
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Distance:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(distance, 1); // One decimal place
  display.print(" cm");
  display.display();

  delay(500);
}
