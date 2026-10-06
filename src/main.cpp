#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RF24.h>

// Screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

// Initialize OLED display (I2C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// NRF24L01+ PA LNA Modules Pin Configuration
// Both share SPI pins: MOSI = 23, MISO = 19, SCK = 18
#define CE1_PIN  4
#define CSN1_PIN 5

#define CE2_PIN  2
#define CSN2_PIN 15

// Initialize radios
RF24 radio1(CE1_PIN, CSN1_PIN);
RF24 radio2(CE2_PIN, CSN2_PIN);

// Noise array for transmission
const uint8_t noiseData[32] = {
  0xFF, 0xAA, 0x55, 0x00, 0xFF, 0xAA, 0x55, 0x00,
  0xFF, 0xAA, 0x55, 0x00, 0xFF, 0xAA, 0x55, 0x00,
  0xFF, 0xAA, 0x55, 0x00, 0xFF, 0xAA, 0x55, 0x00,
  0xFF, 0xAA, 0x55, 0x00, 0xFF, 0xAA, 0x55, 0x00
};

void setup() {
  Serial.begin(115200);
  
  // Initialize Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
  } else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("Team Electroboom"));
    display.println(F("Jammer Initializing"));
    display.display();
    delay(2000);
  }

  // Initialize Radio 1
  if (radio1.begin()) {
    radio1.setAutoAck(false);
    radio1.stopListening();
    radio1.setRetries(0, 0);
    radio1.setPALevel(RF24_PA_MAX, true); // true indicates LNA is used
    radio1.setDataRate(RF24_2MBPS);
    Serial.println(F("Radio 1 Initialized"));
  } else {
    Serial.println(F("Radio 1 Failed"));
  }

  // Initialize Radio 2
  if (radio2.begin()) {
    radio2.setAutoAck(false);
    radio2.stopListening();
    radio2.setRetries(0, 0);
    radio2.setPALevel(RF24_PA_MAX, true); // true indicates LNA is used
    radio2.setDataRate(RF24_2MBPS);
    Serial.println(F("Radio 2 Initialized"));
  } else {
    Serial.println(F("Radio 2 Failed"));
  }
}

void loop() {
  // Sweep across the 2.4GHz spectrum
  // Channels 1 to 83 cover the typical Wi-Fi and Bluetooth frequency range
  for (int ch = 1; ch < 84; ch++) {
    
    // Split the load: Radio 1 handles lower half, Radio 2 handles upper half offsets
    radio1.setChannel(ch);
    radio2.setChannel((ch + 40) % 84); // 40 channels apart for wide disruption
    
    // Transmit garbage data multiple times per channel to increase interference
    for (int i = 0; i < 5; i++) {
      radio1.writeFast(&noiseData, sizeof(noiseData));
      radio2.writeFast(&noiseData, sizeof(noiseData));
    }
    
    // Update display occasionally to show activity without slowing down the loop too much
    if (ch % 20 == 0) {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Team Electroboom"));
      display.println(F("Status: JAMMING"));
      display.print(F("Current CH: "));
      display.println(ch);
      display.display();
    }
  }
}
