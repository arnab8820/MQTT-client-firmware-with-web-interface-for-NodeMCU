//this is the main program that is the entry point of the project
//Author: Arnab Ghosh
//Website: http://arnab8820.tk
//Date: 15/04/2019

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <ESP8266HTTPClient.h>

#define LED D4
#define TEMP A0

//Global variables
String webpage = "";
bool wificonnected = false, hostnameset = false, mqttconfigset = false, devmapconfigset = false;
char* clientssid;
char* clientpass;
char* devhostname;
char* mqtthost;
int mqttport;
char* mqttuser;
char* mqttpass;
char* channel1;
char* channel2;
char* channel3;
char* channel4;
char* channel5;
char* channel6;
char* channel7;
char* channel8;
unsigned long int interval;

//Credentials for WiFi Access Point mode
const char *ssid = "AI-Smart";
const char *pass = "password";


//starting server at port 80
ESP8266WebServer server(80);

//initializing pubsub client
WiFiClient espClient;
void callback(char* topic, byte* payload, unsigned int length);
PubSubClient client(espClient);


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);    //Built in LED as output
  pinMode(TEMP, INPUT);
  
  Serial.begin(115200);
  Serial.println("Serial begin");
  Serial.println("SPIFFS begin");
  if(!SPIFFS.begin())
  {
    Serial.println("Error opening SPIFFS");
  }
  getConfig();  
  checkWifi();  
  server.on("/", handleRoot);
  server.on("/savewifiinfo", HTTP_POST, handlewifiupdate);
  server.on("/savehostinfo", HTTP_POST, handlehostupdate);
  server.on("/savemqttdata", HTTP_POST, handlemqttupdate);
  server.on("/savedevicedata", HTTP_POST, handledevicemapupdate);
  Serial.println("Server begin");
  server.begin();
  interval = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  if(millis() - interval >= 2000){
    interval=millis();
    if(client.connected() == true){
      publishTemperature();
    }
        
  }
  if(mqttconfigset == true && client.connected() == false){
    mqttConnect();
  }
  /*if(WiFi.status() != WL_CONNECTED){
    wificonnected = false;
    checkWifi();
  }*/
  //client.ping();
}
