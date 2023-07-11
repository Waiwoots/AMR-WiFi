
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>    //https://github.com/esp8266/Arduino
#include <ESP8266HTTPClient.h>
//#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>     //https://github.com/tzapu/WiFiManager
#include <SoftwareSerial.h>
#include <Scheduler.h> 
//#include <ArduinoOTA.h>
#include <ESP8266httpUpdate.h>
//#include <WiFiClient.h>

#include "Funct.h";
//////////////////////
#include <EEPROM.h>
int address = 0;
byte value[32];
//////////////////////
#include "Configure.h"; //ควรอยู่ใต้ String Site =("xxx");

#define _SS_MAX_RX_BUFF 256

SoftwareSerial chat(D1,D2); // RX, TX   

int x;
String data;
String data2;

// set pin numbers:
//#define D0 16             // USER LED Wake
//#define ledPin  0        // the number of the LED pin

#define LedGreenOut      D3   // LED Green Out
//#define D1 5              //ค่าเก่าซ้ำซ้อนกัน
//#define ConfigWiFi_Pin D1 //ค่าเก่าซ้ำซ้อนกัน
#define ConfigWiFi_Pin D5
//#define ESP_AP_NAME "ESP8266 Config AP"

const int ledPin =  LED_BUILTIN;
int ledState = LOW; 
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 400; 

 
 int Mux1,Mux2,Mux3,Mux4,Mux5,reboot  ;

 String json ;

#include "json.h";
#include "send.h";

/*
void WiFiEvent(WiFiEvent_t event) {
    Serial.printf("[WiFi-event] event: %d\n", event);

    switch(event) {
        case WIFI_EVENT_STAMODE_GOT_IP:
            Serial.println("WiFi connected");
            Serial.println("IP address: ");
            Serial.println(WiFi.localIP());
            break;
        case WIFI_EVENT_STAMODE_DISCONNECTED:
            Serial.println("WiFi lost connection");
            break;
    }
}
*/
void setup()
{

 pinMode(LedGreenOut , OUTPUT);
 pinMode(ledPin, OUTPUT);



 
 Serial.begin(9600);  
 while (!Serial) continue;
 
  chat.begin(4800);
 while (!chat) continue;
 // digitalWrite(ledPin, LOW); //Turn on the LED
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around

/////////////////////////
 /*   WiFi.disconnect(true);

    delay(1000);

    WiFi.onEvent(WiFiEvent);

*/

//////////////////////

  

 // WiFi.mode(WIFI_STA);
  WiFiManager wifiManager;
  if (digitalRead(ConfigWiFi_Pin) == LOW) // Press button
  {
    //reset saved settings
    wifiManager.resetSettings(); // go to ip 192.168.4.1 to config
  }
  //fetches ssid and password from EEPROM and tries to connect
  //if it does not connect, it starts an access point with the specified name
  //and goes into a blocking loop awaiting configuration


wifiManager.autoConnect("AutoConnectAP");
  
  wifiManager.autoConnect(ESP_AP_NAME.c_str());
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
    digitalWrite(LedGreenOut , LOW);
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  Site = Mac_Station(WiFi.macAddress());
  Serial.println("Station: "+String(Site));
  Serial.print("ESP.getChip:");
  Serial.println(ESP.getChipId());
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.psk());
  
/*//////////////////// การ upload firmware ผ่านทาง WiFi \\\\\\\\\\\\*/
/*     ArduinoOTA.onStart([]() {
            String type;
                 if (ArduinoOTA.getCommand() == U_FLASH) {
                     type = "sketch";
                        } else { // U_FS
                                type = "filesystem";
                                }
                          // NOTE: if updating FS this would be the place to unmount FS using FS.end()
                                Serial.println("Start updating " + type);
                               });
     ArduinoOTA.onEnd([]() {
                Serial.println("\nEnd");
                                 });
     ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
                Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
                                 });
    ArduinoOTA.onError([](ota_error_t error) {
                                         Serial.printf("Error[%u]: ", error);
                                         if (error == OTA_AUTH_ERROR) {
                                          Serial.println("Auth Failed");
                                       } else if (error == OTA_BEGIN_ERROR) {
                                           Serial.println("Begin Failed");
                                       } else if (error == OTA_CONNECT_ERROR) {
                                           Serial.println("Connect Failed");
                                       } else if (error == OTA_RECEIVE_ERROR) {
                                          Serial.println("Receive Failed");
                                      } else if (error == OTA_END_ERROR) {
                                           Serial.println("End Failed");
                                       }
                                           });
          ArduinoOTA.begin();

          */
                          /*//////////////////// การ upload firmware ผ่านทาง WiFi \\\\\\\\\\\\*/

   upintheair();
  Scheduler.start(&send_task);
  Scheduler.start(&json_task);
   
   Scheduler.begin();  

}
void loop()
{
 

}


void memoryRead ()

{
 while (address <= 32, address++) {
    value[address] = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value[address], DEC);
  Serial.println();

 
  //address = address + 1;
  
 
  }
  
  
  }

  
void memoryWrite ()

{
  address = 0;
 while (address <= 32, address++) {
    value[address] = EEPROM.read(address);

   EEPROM.write(address,value[address] );


  if (address == 32) {

  EEPROM.commit();
      Serial.println("EEPROM successfully committed");
  
  }
  
 
  }
  
  
  }

void upintheair()
{
   
  String fwURL = String( firmwareUrlBase );
  fwURL.concat( firmware_name );
  String fwVersionURL = fwURL;
  fwVersionURL.concat( ".version" );
 
  Serial.println( "Checking for firmware updates." );
  // Serial.print( "MAC address: " );
  // Serial.println( mac );
  Serial.print( "Firmware version URL: " );
  Serial.println( fwVersionURL );
  
 WiFiClient client;
  HTTPClient http;
  http.begin(client, fwVersionURL );
  int httpCode = http.GET();
  if( httpCode == 200 ) {
    String newFWVersion = http.getString();
 
    Serial.print( "Current firmware version: " );
    Serial.println( FW_VERSION );
    Serial.print( "Available firmware version: " );
    Serial.println( newFWVersion );
    Serial.println( UpdateTime );
 
   int newVersion = newFWVersion.toInt();
 
    if( newVersion > FW_VERSION ) {
      Serial.println( "Preparing to update" );
       memoryRead(); //อ่านค่า SSID PASSWORD จาก EEPROM/Flash เข้าสู่ Array
      String fwImageURL = fwURL;
      fwImageURL.concat( ".bin" );
      t_httpUpdate_return ret = ESPhttpUpdate.update( client,fwImageURL );
      memoryWrite(); //เขียนค่า SSID PASSWORD จาก Array ไปยัง EEPROM/Flash  


      
 
      switch(ret) {
        case HTTP_UPDATE_FAILED:
          Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
          break;
 
        case HTTP_UPDATE_NO_UPDATES:
          Serial.println("HTTP_UPDATE_NO_UPDATES");
          break;
      }
    }
    else {
      Serial.println( "Already on latest version" );
      http.end();
    }
  }
  else {
    Serial.print( "Firmware version check failed, got HTTP response code " );
    Serial.println( httpCode );
  }
  http.end();

  
}
