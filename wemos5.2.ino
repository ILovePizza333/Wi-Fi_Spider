#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>//библиотека для обновления по WiFi

const char* APssid = "Spider"; const char* APpassword = "12345678";
const char* ssid = "UPVEL"; const char* password = "12345678";
ESP8266WebServer server(80);

IPAddress ip (192, 168, 10, 160);//локальный ip //не забывай про обновление 67 -я 209- влад
IPAddress gateway (192, 168, 10, 1);//адрес роутера в сети
IPAddress subnet (255, 255, 255, 0);//макска подсети
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

#define WIFIMODE 0 //  0-Spider-main 1-Smartphone-main

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// По умолчанию модуль доступен по адресу I2C 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();// При необходимости вы можете задать другой адрес, например 0x41 //Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

#define SERVOMIN  160 // минимальная длительность импульса для сервомашинки
#define SERVOMAX  650 // максимальная длина импульса для сервомашинки




int SERVOPORT[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14};// не подключай к 0 контакту, тк он при включении вай фая дергается //8 контакт умер
int servo_prev[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};// stand
int servo_stand[] = {100, 140, 25, 100, 140, 0, 100, 130, 0, 100, 140, 25};// stand
int servo_sit[] = {100, 180, 25, 100, 180, 25, 100, 180, 25, 100, 180, 25};// stand
int Move =0;
int s = 0;
String slider;
int Sliderr[] = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};

void setup() {
  Serial.begin(115200);
  Serial.println("");
  pwm.begin();
  pwm.setPWMFreq(60);  // Частота следования импульсов 60 Гц по умолчанию // у sg90 50гц
  delay(10);


  if (WIFIMODE == 0) {
    Serial.println("SoftAP");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(APssid, APpassword);
    Serial.print("Spider IP = ");    Serial.println(WiFi.softAPIP());
  }
  if (WIFIMODE == 1) {
    WiFi.mode(WIFI_STA);
    WiFi.config(ip, gateway, subnet, primaryDNS, secondaryDNS);
    WiFi.begin(ssid, password);

    Serial.println("");

    // ждем соединения:
    
      while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      }
    
    Serial.println("");
    Serial.print("Connected to ");  Serial.println(ssid);
    Serial.print("IP address: ");  Serial.println(WiFi.localIP());
  }
  command();
  server.begin();

//start_handler();
  //sit2_handler();
  stand_handler();
  // bt_handler();

  ArduinoOTA.setPort(8266);// порт для обновления по WiFi
  ArduinoOTA.setHostname("Spider");// имя устройства для обновления по WiFi
  ArduinoOTA.begin();//старт возможности беспроводного обновления
}

void loop() {
  //Serial.println("x");
  server.handleClient();
  server.handleClient();
  /*if (Move==1){
    forw_handler();
  }
    else if (Move==2){
    back_handler();
  }
    else if (Move==3){
    left_handler();
  }
    else if (Move==4){
    right_handler();
  }
      else if (Move==5){
    f2_handler();
  }*/
  ArduinoOTA.handle();//при наличии обновления- устанавливаем
}
