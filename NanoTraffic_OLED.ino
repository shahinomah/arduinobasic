#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED reset pin (not used, so set to -1)
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// LED pins
const int ledRed = 8;
const int ledYellow = 7;
const int ledGreen = 6;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { //0x78)) { 
    Serial.println("OLED not found. Check wiring.");
    while (true);  // Halt
  }

  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("System Ready");
  display.display();
  delay(1500);
  display.clearDisplay();
}

void loop() {
  // GREEN light
  digitalWrite(ledGreen, HIGH);
  Serial.println("GO >>>");
  showOnOLED("GO >>>");
  delay(2000);
  digitalWrite(ledGreen, LOW);
  delay(500);

  // YELLOW light
  digitalWrite(ledYellow, HIGH);
  Serial.println("SLOW DOWN");
  showOnOLED("SLOW DOWN");
  delay(2000);
  digitalWrite(ledYellow, LOW);
  delay(500);

  // RED light
  digitalWrite(ledRed, HIGH);
  Serial.println("STOP !!!");
  showOnOLED("STOP !!!");
  delay(2000);
  digitalWrite(ledRed, LOW);
  delay(500);

  Serial.println("");
}

// Helper function to display text on OLED
void showOnOLED(String message) {
  display.clearDisplay();
  display.setCursor(0, 10);
  display.setTextSize(2);
  display.println(message);
  display.display();
}
