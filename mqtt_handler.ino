bool mqttConnect(){
  Serial.println("Connecting to MQTT broker ...");
  client.setServer(mqtthost, mqttport);
  client.setCallback(callback);
  if(client.connect(devhostname, mqttuser, mqttpass)){
    Serial.println("Connected to broker.");
    return true;
  }
  else{
    Serial.println("Failed to connect broker!");
    //mqttConnect();
    return false;
  }
}

void publishTemperature(){
  float temp = (3000.0*(analogRead(TEMP)-7)/10170.0);
  char buf[5];
  sprintf(buf, "%0.2f", temp);
  char topic[50];
  sprintf(topic, "%s/temp", devhostname);
  client.publish(topic, buf);
     
  Serial.print("Value published: ");
  Serial.println(buf);
}

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived
}
