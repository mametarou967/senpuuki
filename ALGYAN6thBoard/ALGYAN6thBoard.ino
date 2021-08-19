#include <Wire.h>
#include "SSD1306.h"//ディスプレイ用ライブラリを読み込み

// Pin define
#define PIN_LED     12
#define PIN_SW1     35
#define PIN_CDS     34
#define PIN_SERVO   13
#define PIN_BUZZAR  14
#define PIN_CN5_I2C_SDA 21
#define PIN_CN5_I2C_SCL 22

#define BUZZAR_LEN  5 // Buzzar length (20 x 5 = 100msec)

SSD1306  display(0x3c, PIN_CN5_I2C_SDA, PIN_CN5_I2C_SCL); //SSD1306インスタンスの作成（I2Cアドレス,SDA,SCL）

void setup() {
  // Setup Serial
  Serial.begin(115200);

  // Setup Pins
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SW1, INPUT);
  pinMode(PIN_CDS, INPUT);
  pinMode(PIN_BUZZAR, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_BUZZAR, LOW);
  Serial.println(" Hello");

  display.init();    //ディスプレイを初期化
  display.setFont(ArialMT_Plain_16);    //フォントを設定
  display.drawString(0, 0, "Hello World");    //(0,0)の位置にHello Worldを表示
  display.display();   //指定された情報を描画
}

void loop() {
}
