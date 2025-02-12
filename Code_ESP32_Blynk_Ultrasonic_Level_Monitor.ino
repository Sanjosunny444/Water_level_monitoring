#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SSD1306_I2C_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Set I2C pins for ESP32
  Wire.begin(22, 21); // SDA=22, SCL=21

  // Initialize OLED display
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
  
  // Display "Hello, World!"
  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 10);    // Start at top-left corner
  display.println(F("Hello, World!"));
  display.display();
}

void loop() {
  // You can add code here to continuously update the display if needed.
}
