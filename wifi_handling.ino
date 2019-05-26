int checkWifi(){
  if(SPIFFS.exists("config-wifi.json")){
    getWifiCredentials();
    connectWifi();
    if(WiFi.status() != WL_CONNECTED){
      wificonnected = false;
      createAP();
    }
    else{
      wificonnected = true;
      digitalWrite(LED, HIGH);
      Serial.print("Connected! IP address: ");
      Serial.println(WiFi.localIP());
    }
  }
  else{
    wificonnected = false;
    createAP();
  }
  WiFi.printDiag(Serial);  
}

//get wifi credentials from wifi configuration file
void getWifiCredentials(){
  File wificonfig = SPIFFS.open("config-wifi.json", "r");
  if(!wificonfig){
    Serial.println("Unable to open configuration file to read!");
    return;
  }
  size_t size = wificonfig.size();
  std::unique_ptr<char[]> buf(new char[size]);
  wificonfig.readBytes(buf.get(), size);
  wificonfig.close();
  DynamicJsonBuffer jBuffer;
  JsonObject& jObject = jBuffer.parseObject(buf.get());
  if(!jObject.success()){
    Serial.println("Can not parse");
  }
  else{
    const char* ssid = jObject["ssid"];
    clientssid = strdup(ssid);
    const char* pass = jObject["password"];
    clientpass = strdup(pass);
  }
}

//function to connect to saved wifi network
void connectWifi(){
  unsigned long timeout = millis();
  WiFi.softAPdisconnect(true);
  WiFi.disconnect();
  digitalWrite(LED, HIGH);
  delay(1000);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(clientssid);
  WiFi.begin(clientssid, clientpass);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED, HIGH);
    delay(500);
    Serial.print(".");
    digitalWrite(LED, LOW);
    delay(100);
    if(millis() - timeout > 30000) break;
  }
}

//create an access point if no wifi credentials saved or they are invalid
void createAP(){
  WiFi.softAPdisconnect(true);
  WiFi.disconnect();
  digitalWrite(LED, HIGH);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IPAddress(192, 168, 1, 2), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
  delay(500);
  WiFi.softAP(ssid, pass);
  digitalWrite(LED, LOW);
}
