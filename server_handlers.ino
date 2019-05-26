//handling server root
void handleRoot() {
  sendPage();
  server.send(200, "text/html", webpage);
}

//handling wifi settings upadate
void handlewifiupdate(){
  digitalWrite(LED, LOW);
  String data = server.arg("plain");    //getting the arguments sent by the client
  File wconf = SPIFFS.open("config-wifi.json", "w");
  if(!wconf)
  {
    Serial.println("Unable to open WiFi configuration file!");
  }
  wconf.print(data);
  wconf.close();
  server.send(200, "text/html", "WiFi data saved successfully! Device will now try to connect to supplied network!");
  delay(1000);
  digitalWrite(LED, HIGH);
  checkWifi();
}

void handlehostupdate(){
  digitalWrite(LED, LOW);
  String data = server.arg("plain");
  File hostconf = SPIFFS.open("config-host.json", "w");
  if(!hostconf){
    Serial.println("Unable to open host configuration file!");
  }
  hostconf.print(data);
  hostconf.close();
  server.send(200, "text/html", "Hostname Saved Successfully! Please reload the page!");
  delay(1000);
  digitalWrite(LED, HIGH);
}

void handlemqttupdate(){
  digitalWrite(LED, LOW);
  String data = server.arg("plain");
  File mqttconf = SPIFFS.open("config-mqtt.json", "w");
  if(!mqttconf){
    Serial.println("Unable to open MQTT configuration file!");
  }
  mqttconf.print(data);
  mqttconf.close();
  server.send(200, "text/html", "MQTT configuration saved successfully!");
  delay(1000);
  digitalWrite(LED, HIGH);
}

void handledevicemapupdate(){
  digitalWrite(LED, LOW);
  String data = server.arg("plain");
  File devmapconf = SPIFFS.open("config-devmap.json", "w");
  if(!devmapconf){
    Serial.println("Unable to open device map file!");
  }
  devmapconf.print(data);
  devmapconf.close();
  server.send(200, "text/html", "Device names saved successfully!");
  delay(1000);
  digitalWrite(LED, HIGH);
}
