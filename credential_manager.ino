//function to get all the configurations
void getConfig(){
  //getting saved hostname for the device
  if(SPIFFS.exists("config-host.json")){
    File hostconfig = SPIFFS.open("config-host.json", "r");
    if(!hostconfig){
      Serial.println("Unable to open host configuration file to read!");
      return;
    }
    size_t size = hostconfig.size();
    std::unique_ptr<char[]> buf(new char[size]);
    hostconfig.readBytes(buf.get(), size);
    hostconfig.close();
    DynamicJsonBuffer jBuffer;
    JsonObject& jObject = jBuffer.parseObject(buf.get());
    if(!jObject.success()){
      Serial.println("Can not parse");
    }
    else{
      const char* temp = jObject["hostname"];
      devhostname = strdup(temp);
      hostnameset = true;
    }
  }

  //getting saved mqtt info
  if(SPIFFS.exists("config-mqtt.json")){
    File mqttconfig = SPIFFS.open("config-mqtt.json", "r");
    if(!mqttconfig){
      Serial.println("Unable to open mqtt configuration file to read!");
      return;
    }
    size_t size = mqttconfig.size();
    std::unique_ptr<char[]> buf(new char[size]);
    mqttconfig.readBytes(buf.get(), size);
    mqttconfig.close();
    DynamicJsonBuffer jBuffer;
    JsonObject& jObject = jBuffer.parseObject(buf.get());
    if(!jObject.success()){
      Serial.println("Can not parse");
    }
    else{
      const char* temp = jObject["mqtt_host"];
      mqtthost = strdup(temp);
      temp = jObject["mqtt_port"];
      mqttport = atoi(temp);
      temp = jObject["mqtt_user"];
      mqttuser = strdup(temp);
      temp = jObject["mqtt_pass"];
      mqttpass = strdup(temp);
      mqttconfigset = true;
    }
  }

  //getting device names for each channel
  if(SPIFFS.exists("config-devmap.json")){
    File devmapconfig = SPIFFS.open("config-devmap.json", "r");
    if(!devmapconfig){
      Serial.println("Unable to open device map configuration file to read!");
      return;
    }
    size_t size = devmapconfig.size();
    std::unique_ptr<char[]> buf(new char[size]);
    devmapconfig.readBytes(buf.get(), size);
    devmapconfig.close();
    DynamicJsonBuffer jBuffer;
    JsonObject& jObject = jBuffer.parseObject(buf.get());
    if(!jObject.success()){
      Serial.println("Can not parse");
    }
    else{
      const char* temp = jObject["c1"];
      channel1 = strdup(temp);
      temp = jObject["c2"];
      channel2 = strdup(temp);
      temp = jObject["c3"];
      channel3 = strdup(temp);
      temp = jObject["c4"];
      channel4 = strdup(temp);
      temp = jObject["c5"];
      channel5 = strdup(temp);
      temp = jObject["c6"];
      channel6 = strdup(temp);
      temp = jObject["c7"];
      channel7 = strdup(temp);
      temp = jObject["c8"];
      channel8 = strdup(temp);
      devmapconfigset = true;
    }
  }
}
