// 範例十五: 
// 透過 7697_EXT 轉板，使用 7697 + ST7789 TFT 來顯示照片
// 7697_EXT 轉板 P10 JMP 請選擇 TFT 

// 使用 7697-SPI 介面
// 圖片的 .c 檔案，由 http://www.rinkydinkelectronics.com/t_imageconverter565.php 轉出
// 圖片大小建議為 220 x 220

// 需要的 library : Adafruit-GFX-Library-7697 , Arduino-ST7789-Library-spi9bit 
// FB : https://www.facebook.com/mason.chen.1420

#include <Adafruit_GFX.h>    // Core graphics library
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
extern const unsigned short PROGMEM gyro220[];  // .C array image data. Convert from http://www.rinkydinkelectronics.com/t_imageconverter565.php

//LCD_ST7789 setting for Gyro shield:
#define TFT_DC    4  
#define TFT_RST   2  
#define TFT_CS    10 
#define TFT_MOSI  11   
#define TFT_SCLK  13  

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_CS); 

void setup(void) {
  Serial.begin(9600);
  Serial.print("Hello! ST7789 TFT Test");

  tft.init(240, 240);   // initialize a ST7789 chip, 240x240 pixels

  Serial.println("Initialized");

  tft.fillScreen(BLACK);

  tft.drawRGBBitmap(10, 10, gyro220, 220, 220);  // Replace your image data
  Serial.println("done");
  delay(1000);
}

void loop() {
}
