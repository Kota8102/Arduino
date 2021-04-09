/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use ESP32 BLE
  to connect your project to Blynk.

  Warning: Bluetooth support is in beta!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT

#include <M5StickCPlus.h>

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(300, 26, NEO_GRB + NEO_KHZ800);

uint8_t red = 0x00, green = 0x00, blue = 0x00;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Iy5NNiFBY7tXzFpYiMMhVUrvy0o_Kj7m";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Serial.println("Waiting for connections...");

  Blynk.setDeviceName("Blynk");

  Blynk.begin(auth);

  pixels.begin();
  pixels.setBrightness(50);
}

void loop()
{
  Blynk.run();
}


//追加部分
BLYNK_WRITE(V0) {
  int16_t LED = param[0].asInt();

  if (LED == 1) {
    red = 0xff;
    green = 0xff;
    blue = 0xff;
    uint32_t RGB888 = red << 16 | green << 8 | blue;
    Serial.println(RGB888);
    for (int i = 0; i < 5; i++) {
      pixels.setPixelColor(i, RGB888);
    }
    pixels.show();
  }
  if (LED == 0) {
    digitalWrite(GPIO_NUM_10, LOW);
    red = 0x00;
    green = 0x00;
    blue = 0x00;
    uint32_t RGB888 = red << 16 | green << 8 | blue;
    Serial.println(RGB888);
    for (int i = 0; i < 5; i++) {
      pixels.setPixelColor(i, RGB888);
    }
    pixels.show();
  }
}

BLYNK_WRITE(V1) {
  int8_t LED_Red = param[0].asInt();

  red = LED_Red;
  uint32_t RGB888 = red << 16 | green << 8 | blue;
  Serial.println(RGB888);
  for (int i = 0; i < 5; i++) {
    pixels.setPixelColor(i, RGB888);
  }
  pixels.show();
}

BLYNK_WRITE(V2) {
  int8_t LED_Green = param[0].asInt();

  green = LED_Green;
  uint32_t RGB888 = red << 16 | green << 8 | blue;
  Serial.println(RGB888);
  for (int i = 0; i < 5; i++) {
    pixels.setPixelColor(i, RGB888);
  }
  pixels.show();
}

BLYNK_WRITE(V3) {
  int8_t LED_Blue = param[0].asInt();

  blue = LED_Blue;
  uint32_t RGB888 = red << 16 | green << 8 | blue;
  Serial.println(RGB888);
  for (int i = 0; i < 5; i++) {
    pixels.setPixelColor(i, RGB888);
  }
  pixels.show();
}
