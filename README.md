# MQTT-client-firmware-with-web-interface-for-NodeMCU
This project is a firmware developed by me. It provides users an web interface to enter their Wi-Fi credentials, MQTT credentials and channel names for each gpio pins of NodeMCU. It saves the credentials into the built in flash memory as JSON configuration files. 

Steps to use this firmware:
1. Flash the main.ino file.
2. Power on the NodeMCU. You will find a Wi-Fi network "AI-Smart".
3. Connect to the network and visit http://192.168.4.1 from a web browser.
4. Enter your Wi-Fi credentials and MQTT credentials and you are good to go.
