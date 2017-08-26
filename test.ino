/***************************************************
  This is an example sketch for the Adafruit 2.2" SPI display.
  This library works with the Adafruit 2.2" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/1480

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include "SPI.h"
#include "Adafruit_GFX.h"
//#include "Adafruit_ILI9340.h"
#include "Adafruit_ILI9341.h"

#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif

// These are the pins used for the UNO
// for Due/Mega/Leonardo use the hardware SPI pins (which are different)
#define _sclk 2 // uno hw spi: 13, icsp: 3
#define _mosi 3 // uno hw spi: 12, icsp: 4
#define _dc 4
#define _cs 5
#define _rst 6
#define _miso 8
// Using software SPI is really not suggested, its incredibly slow
//Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _mosi, _sclk, _rst, _miso);
// Use hardware SPI
//Adafruit_ILI9340 tft = Adafruit_ILI9340(_cs, _dc, _rst);
// For the Adafruit shield, these are the default.
#define TFT_DC 4
#define TFT_CS 5
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
#define LED_PIN 7

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  Serial.begin(115200);
  while (!Serial);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);
  tft.setTextWrap(true);
  tft.println("CONSOLE>");
  digitalWrite(LED_PIN, LOW);
}

void loop(void) {
  /*tft.println("[1020358.156608] mwifiex_pcie 0000:01:00.0: PREP_CMD: FW in reset state");
    tft.println("[1020358.156612] mwifiex_pcie 0000:01:00.0: scan failed: -1");
    tft.println("[1020358.156608] mwifiex_pcie 0000:01:00.0: PREP_CMD: FW in reset state");
    tft.println("[1020358.156612] mwifiex_pcie 0000:01:00.0: scan failed: -1");
    tft.println("[1020358.156608] mwifiex_pcie 0000:01:00.0: PREP_CMD: FW in reset state");
    tft.println("[1020358.156612] mwifiex_pcie 0000:01:00.0: scan failed: -1");
    tft.println("[1020358.156608] mwifiex_pcie 0000:01:00.0: PREP_CMD: FW in reset state");
    tft.println("[1020358.156612] mwifiex_pcie 0000:01:00.0: scan failed: -1");
    tft.println("[1020358.156608] mwifiex_pcie 0000:01:00.0: PREP_CMD: FW in reset state");
    tft.println("[1020358.156612] mwifiex_pcie 0000:01:00.0: scan failed: -1");
    tft.println("[1020358.156608] mwifiex_pcie 0000:01:00.0: PREP_CMD: FW in reset state");
    tft.println("[1020358.156612] mwifiex_pcie 0000:01:00.0: scan failed: -1");
    delay(500);*/
  //char incomingByte = 0;   // for incoming serial data
  char serbuf[255];
  if (Serial.available() > 0) {
    digitalWrite(LED_PIN, HIGH);
    // read the incoming byte:
    //incomingByte = Serial.read();
    Serial.readBytes(serbuf, 255);
    // say what you got:
    //Serial.print(incomingByte);
    tft.print(serbuf);
    delay(10);
    digitalWrite(LED_PIN, LOW);
  }
}
