//Generate the webpage
void sendPage()
{
  getConfig();
  webpage = "<!DOCTYPE html>\n";
  webpage += "<html>\n";
  webpage += "<head>\n";
  webpage += "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
  webpage += "\t<title>Client Control</title>\n";
  webpage += "\n";
  webpage += "\t<style type=\"text/css\">\n";
  webpage += "\t\tbody{\n";
  webpage += "\t\t\tbackground: #e5e5e5;\n";
  webpage += "\t\t\tfont-family: sans-serif;\n";
  webpage += "\t\t\tmargin: 0;\n";
  webpage += "\t\t}\n";
  webpage += "\n";
  webpage += "\t\t.header{\n";
  webpage += "\t\t\twidth: 100%;\n";
  webpage += "\t\t\tbackground: #4286f4;\n";
  webpage += "\t\t\tcolor: white;\n";
  webpage += "\t\t\tfont-size: 26px;\n";
  webpage += "\t\t}\n";
  webpage += "\n";
  webpage += "\t\t.logo{\n";
  webpage += "\t\t\tpadding: 10px 15px;\n";
  webpage += "\t\t\twidth: auto;\n";
  webpage += "\t\t}\n";
  webpage += "\n";
  webpage += "\t\t.body{\n";
  webpage += "\t\t\tmargin: auto;\n";
  webpage += "\t\t\twidth: 90%;\n";
  webpage += "\t\t}\n";
  webpage += "\n";
  webpage += "\t\t.section{\n";
  webpage += "\t\t\twidth: 100%;\n";
  webpage += "\t\t\tbackground: #fff;\n";
  webpage += "\t\t\tmargin: 20px 0;\n";
  webpage += "\t\t\tpadding: 10px 0;\n";
  webpage += "\t\t}\n";
  webpage += "\n";
  webpage += "\t\t.welcome{\n";
  webpage += "\t\t\tfont-size: 30px;\n";
  webpage += "\t\t\ttext-align: center;\n";
  webpage += "\t\t\tpadding: 20px 0;\n";
  webpage += "\t\t}\n";
  webpage += "\n";
  webpage += "\t\th4{\n";
  webpage += "\t\t\tpadding: 10px 5px;\n";
  webpage += "\t\t\tmargin: 0px;\n";
  webpage += "\t\t}\n";
  webpage += "\t\t.form{\n";
  webpage += "\t\t\tmargin: 0px 15px;\n";
  webpage += "\t\t}\n";
  webpage += "\t\tp{\n";
  webpage += "\t\t\tmargin: 10px 15px;\n";
  webpage += "\t\t\tfont-size: 14px;\n";
  webpage += "\t\t}\n";
  webpage += "\t\tinput{\n";
  webpage += "\t\t\tdisplay: inline-block;\n";
  webpage += "\t\t\twidth: 250px;\n";
  webpage += "\t\t\theight: 25px;\n";
  webpage += "\t\t\tmargin: 5px;\n";
  webpage += "\t\t}\n";
  webpage += "\t\tinput[type=\"submit\"]{\n";
  webpage += "\t\t\twidth: 50px;\n";
  webpage += "\t\t\theight: 30px;\n";
  webpage += "\t\t\tbackground: #4286f4;\n";
  webpage += "\t\t\tcolor: white;\n";
  webpage += "\t\t\tborder: 0px;\n";
  webpage += "\t\t}\n";
  webpage += "\t</style>\n";
  webpage += "</head>\n";
  webpage += "<body onload=\"checkhost();\">\n";
  webpage += "<div class=\"header\">\n";
  webpage += "\t<div class=\"logo\">\n";
  webpage += "\t\tClient control\n";
  webpage += "\t</div>\n";
  webpage += "</div>\n";
  webpage += "\t\n";
  webpage += "<div class=\"body\">\n";
  webpage += "\t<div class=\"section\">\n";
  webpage += "\t\t<div class=\"welcome\">Welcome to device control panel</div>\n";
  webpage += "\t</div>\n";
  webpage += "\t<div class=\"section\">\n";
  webpage += "\t\t<h4>WiFi Settings</h4>\n";
  webpage += "\t\t<p>Enter your new wifi credential</p>\n";
  webpage += "\t\t<div class=\"form\" id=\"wificredentials\">\t\t\t\n";
  if(wificonnected == true){
    webpage = webpage + "\t\t\t<input type=\"name\" id=\"ssid\" placeholder=\"Your WiFi SSID\" value=\"" + clientssid + "\">\n";
    webpage = webpage + "\t\t\t<input type=\"password\" id=\"password\" placeholder=\"Your WiFi password\" value=\"" + clientpass + "\">\n";
    webpage += "\t\t\t<input type=\"submit\" name=\"submit\" value=\"Save\" onclick=\"savewifi();\">\n";
    webpage = webpage + "<p>WiFi Connected to " + clientssid +".</p>";
  }
  else{
    webpage += "\t\t\t<input type=\"name\" id=\"ssid\" placeholder=\"Your WiFi SSID\">\n";
    webpage += "\t\t\t<input type=\"password\" id=\"password\" placeholder=\"Your WiFi password\">\n";
    webpage += "\t\t\t<input type=\"submit\" name=\"submit\" value=\"Save\" onclick=\"savewifi();\">\n";
  }
  webpage += "\t\t</div>\n";
  webpage += "\t</div>\n";
  webpage += "\t<div class=\"section\">\n";
  webpage += "\t\t<h4>Hostname</h4>\n";
  webpage += "\t\t<p>Enter a hostname without space in between</p>\n";
  webpage += "\t\t<div class=\"form\" id=\"hostcredentials\">\t\t\t\n";
  if(hostnameset == true){
    webpage = webpage + "\t\t\t<input type=\"name\" id=\"hostname\" placeholder=\"Hostname. eg. bedroom, living_room\" value=\"" + devhostname + "\">\n";
  }
  else{
    webpage += "\t\t\t<input type=\"name\" id=\"hostname\" placeholder=\"Hostname. eg. bedroom, living_room\">\n";
  }
  webpage += "\t\t\t<input type=\"submit\" name=\"submit\" value=\"Save\" onclick=\"savehost();\">\n";
  webpage += "\t\t</div>\n";
  webpage += "\t</div>\n";
  webpage += "\t<div class=\"section\">\n";
  webpage += "\t\t<h4>MQTT Settings</h4>\n";
  webpage += "\t\t<p>Enter your MQTT settings</p>\n";
  webpage += "\t\t<div class=\"form\" id=\"mqttcredentials\">\t\t\t\n";
  if(mqttconfigset == true){
    webpage = webpage + "\t\t\t<input type=\"name\" id=\"mqtt_host\" placeholder=\"MQTT hostname or ip\" value=\"" + mqtthost + "\">\n";
    webpage = webpage + "\t\t\t<input type=\"name\" id=\"mqtt_port\" placeholder=\"MQTT port\" value=\"" + mqttport + "\">\n";
    webpage = webpage + "\t\t\t<input type=\"name\" id=\"mqtt_user\" placeholder=\"MQTT username\" value=\"" + mqttuser + "\">\n";
    webpage = webpage + "\t\t\t<input type=\"name\" id=\"mqtt-pass\" placeholder=\"MQTT password\" value=\"" + mqttpass + "\">\n";
    
  }
  else{
    webpage += "\t\t\t<input type=\"name\" id=\"mqtt_host\" placeholder=\"MQTT hostname or ip\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"mqtt_port\" placeholder=\"MQTT port\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"mqtt_user\" placeholder=\"MQTT username\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"mqtt-pass\" placeholder=\"MQTT password\">\n";
  }
  
  webpage += "\t\t\t<input type=\"submit\" name=\"submit\" value=\"Save\" onclick=\"savemqtt();\">\n";
  webpage += "\t\t</div>\n";
  webpage += "\t</div>\n";
  webpage += "\t<div class=\"section\" id=\"hardware\">\n";
  webpage += "\t\t<h4>Device Mapping</h4>\n";
  webpage += "\t\t<p>Enter names for each of your coonected devices. (Eg. Lightbulb, Ceiling_light, Fan etc.)</p>\n";
  webpage += "\t\t<div class=\"form\" id=\"devmap\">\n";
  if(devmapconfigset == true){
    if(strcmp(channel1, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c1\" placeholder=\"Channel 1\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c1\" placeholder=\"Channel 1\" value=\"" + channel1 + "\">\n";
    }
    if(strcmp(channel2, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c2\" placeholder=\"Channel 2\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c2\" placeholder=\"Channel 2\" value=\"" + channel2 + "\">\n";
    }
    if(strcmp(channel3, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c3\" placeholder=\"Channel 3\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c3\" placeholder=\"Channel 3\" value=\"" + channel3 + "\">\n";
    }
    if(strcmp(channel4, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c4\" placeholder=\"Channel 4\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c4\" placeholder=\"Channel 4\" value=\"" + channel4 + "\">\n";
    }
    if(strcmp(channel5, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c5\" placeholder=\"Channel 5\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c5\" placeholder=\"Channel 5\" value=\"" + channel5 + "\">\n";
    }
    if(strcmp(channel6, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c6\" placeholder=\"Channel 6\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c6\" placeholder=\"Channel 6\" value=\"" + channel6 + "\">\n";
    }
    if(strcmp(channel7, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c7\" placeholder=\"Channel 7\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c7\" placeholder=\"Channel 7\" value=\"" + channel7 + "\">\n";
    }
    if(strcmp(channel8, "null") == 0){
      webpage += "\t\t\t<input type=\"name\" id=\"c8\" placeholder=\"Channel 8\">\n";     
    }
    else{
      webpage = webpage + "\t\t\t<input type=\"name\" id=\"c8\" placeholder=\"Channel 8\" value=\"" + channel8 + "\">\n";
    }
  }
  else{
    webpage += "\t\t\t<input type=\"name\" id=\"c1\" placeholder=\"Channel 1\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c2\" placeholder=\"Channel 2\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c3\" placeholder=\"Channel 3\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c4\" placeholder=\"Channel 4\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c5\" placeholder=\"Channel 5\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c6\" placeholder=\"Channel 6\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c7\" placeholder=\"Channel 7\">\n";
    webpage += "\t\t\t<input type=\"name\" id=\"c8\" placeholder=\"Channel 8\">\n";
  }
  webpage += "\t\t\t<input type=\"submit\" name=\"submit\" value=\"Save\" onclick=\"savedevice();\">\n";
  webpage += "\t\t</div>\n";
  webpage += "\t</div>\n";
  webpage += "</div>\n";
  webpage += "<script type=\"text/javascript\">\n";
  webpage += "\tfunction checkhost()\n";
  webpage += "\t{\n";
  webpage += "\t\tif(document.getElementById(\"hostname\").value.length < 1)\n";
  webpage += "\t\t{\n";
  webpage += "\t\t\tconsole.log(\"Hostname error!\");\n";
  webpage += "\t\t\tdocument.getElementById(\"devmap\").style.display = \"none\";\n";
  webpage += "\t\t\tdocument.getElementById(\"hardware\").getElementsByTagName(\"P\")[0].innerHTML = \"Available after setting hostname!\";\n";
  webpage += "\t\t}\n";
  webpage += "\t}\n";
  webpage += "\n";
  webpage += "\tfunction savewifi()\n";
  webpage += "\t{\n";
  webpage += "\t\tvar ssid = document.getElementById(\"ssid\").value;\n";
  webpage += "\t\tvar password = document.getElementById(\"password\").value;\n";
  webpage += "\t\tvar data = {ssid:ssid, password:password};\n";
  webpage += "\t\tvar xhr = new XMLHttpRequest();\n";
  webpage += "\t\txhr.onreadystatechange = function() {\n";
  webpage += "\t\t\tif (this.status == 200) {\n";
  webpage += "\t\t\t\tvar res = this.responseText;\n";
  webpage += "\t\t\t\tdocument.getElementById(\"wificredentials\").innerHTML = \"<p>\" + res + \"</p>\";\n";
  webpage += "\t\t\t}\n";
  webpage += "\t\t};\n";
  webpage += "\t\txhr.open(\"POST\", \"/savewifiinfo\", true);\n";
  webpage += "\t\txhr.send(JSON.stringify(data));\n";
  webpage += "\t}\n";
  webpage += "\n";
  webpage += "\tfunction savehost() {\n";
  webpage += "\t\tvar hostname = document.getElementById(\"hostname\").value;\n";
  webpage += "\t\tvar data = {hostname:hostname};\n";
  webpage += "\t\tvar xhr = new XMLHttpRequest();\n";
  webpage += "\t\txhr.onreadystatechange = function(){\n";
  webpage += "\t\t\tif (this.status == 200) {\n";
  webpage += "\t\t\t\tdocument.getElementById(\"hostcredentials\").innerHTML = \"<p>\" + this.responseText + \"</p>\";\n";
  webpage += "\t\t\t}\n";
  webpage += "\t\t}\n";
  webpage += "\t\txhr.open(\"POST\", \"/savehostinfo\", true);\n";
  webpage += "\t\txhr.send(JSON.stringify(data));\n";
  webpage += "\t}\n";
  webpage += "\n";
  webpage += "\tfunction savemqtt(){\n";
  webpage += "\t\tvar host = document.getElementById(\"mqtt_host\").value;\n";
  webpage += "\t\tvar port = document.getElementById(\"mqtt_port\").value;\n";
  webpage += "\t\tvar user = document.getElementById(\"mqtt_user\").value;\n";
  webpage += "\t\tvar pass = document.getElementById(\"mqtt-pass\").value;\n";
  webpage += "\t\tvar data = {mqtt_host:host, mqtt_port:port, mqtt_user:user, mqtt_pass:pass};\n";
  webpage += "\t\tvar xhr = new XMLHttpRequest();\n";
  webpage += "\t\txhr.onreadystatechange = function(){\n";
  webpage += "\t\t\tif (this.status == 200) {\n";
  webpage += "\t\t\t\tdocument.getElementById(\"mqttcredentials\").innerHTML = \"<p>\" + this.responseText + \"</p>\";\n";
  webpage += "\t\t\t}\n";
  webpage += "\t\t}\n";
  webpage += "\t\txhr.open(\"POST\", \"/savemqttdata\", true);\n";
  webpage += "\t\txhr.send(JSON.stringify(data));\n";
  webpage += "\t}\n";
  webpage += "\n";
  webpage += "\tfunction savedevice(){\n";
  webpage += "\t\tvar c1 = ((document.getElementById(\"c1\").value.length < 1)? \"null\" : document.getElementById(\"c1\").value);\n";
  webpage += "\t\tvar c2 = ((document.getElementById(\"c2\").value.length < 1)? \"null\" : document.getElementById(\"c2\").value);\n";
  webpage += "\t\tvar c3 = ((document.getElementById(\"c3\").value.length < 1)? \"null\" : document.getElementById(\"c3\").value);\n";
  webpage += "\t\tvar c4 = ((document.getElementById(\"c4\").value.length < 1)? \"null\" : document.getElementById(\"c4\").value);\n";
  webpage += "\t\tvar c5 = ((document.getElementById(\"c5\").value.length < 1)? \"null\" : document.getElementById(\"c5\").value);\n";
  webpage += "\t\tvar c6 = ((document.getElementById(\"c6\").value.length < 1)? \"null\" : document.getElementById(\"c6\").value);\n";
  webpage += "\t\tvar c7 = ((document.getElementById(\"c7\").value.length < 1)? \"null\" : document.getElementById(\"c7\").value);\n";
  webpage += "\t\tvar c8 = ((document.getElementById(\"c8\").value.length < 1)? \"null\" : document.getElementById(\"c8\").value);\n";
  webpage += "\t\tvar data = {c1:c1, c2:c2, c3:c3, c4:c4, c5:c5, c6:c6, c7:c7, c8:c8};\n";
  webpage += "\t\tvar xhr = new XMLHttpRequest();\n";
  webpage += "\t\txhr.onreadystatechange = function(){\n";
  webpage += "\t\t\tif (this.status == 200) {\n";
  webpage += "\t\t\t\tdocument.getElementById(\"devmap\").innerHTML = \"<p>\" + this.responseText + \"</p>\";\n";
  webpage += "\t\t\t}\n";
  webpage += "\t\t}\n";
  webpage += "\t\txhr.open(\"POST\", \"/savedevicedata\", true);\n";
  webpage += "\t\txhr.send(JSON.stringify(data));\n";
  webpage += "\t}\n";
  webpage += "</script>\n";
  webpage += "</body>\n";
  webpage += "</html>";
}
