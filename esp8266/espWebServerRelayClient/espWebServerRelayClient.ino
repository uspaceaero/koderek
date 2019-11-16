#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Main web page
const char MAIN_page[] PROGMEM = R"=====(
  <!DOCTYPE html>
  <html>
  <body>
  <center>
  <h1>WiFi RELAY on/off demo:</h1><br>
  Ciclk to turn <a href="ledOn">RELAY ON</a><br>
  Ciclk to turn <a href="ledOff">RELAY OFF</a><br>
  <hr>
  <a href="http://koderek.edu.pl">koderek.edu.pl</a>
  </center>
  
  </body>
  </html>
)=====";
String mainPage = MAIN_page;
 
// Static IP configuration
IPAddress staticIP(192, 168, 43, 11);
IPAddress gateway(192, 168, 43, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8); 
 
const char* deviceName = "koderek";

// LED Connected to GPIO2 from ESP-01
#define LED 1
// LED Connected to GPIO2 from ESP-01S
//#define LED 2
// RELAY Connected to GPIO0
#define RELAY 0
 
//SSID configuration
const char* ssid = "ESPKODEREK";
const char* password = "ESPKODEREK";
 
// Web server port 80
ESP8266WebServer server(80);
 
// Visit home page
void handleRoot() {
 Serial.println("Home page called");
 server.send(200, "text/html", mainPage);
}

// 
void handleLEDon() { 
 Serial.println("LED/RELAY on");
 digitalWrite(LED,LOW);
 digitalWrite(RELAY,HIGH);
 server.send(200, "text/html", mainPage);
}
 
void handleLEDoff() { 
 Serial.println("LED/RELAY off ");
 digitalWrite(LED,HIGH);
 digitalWrite(RELAY,LOW);
 server.send(200, "text/html", mainPage);
}

void setup(void){
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println(""); 
  
  pinMode(LED,OUTPUT); 
  pinMode(RELAY, OUTPUT);
  digitalWrite(LED,HIGH);
  digitalWrite(RELAY,LOW);
 
  WiFi.disconnect();

  // ESP-01
  WiFi.hostname(deviceName);
  WiFi.config(staticIP, gateway, subnet);
  WiFi.begin(ssid, password);

  // ESP-01S
  //WiFi.hostname(deviceName);
  //WiFi.config(staticIP, dns, gateway, subnet);
  //WiFi.begin(ssid, password);
 
  WiFi.mode(WIFI_STA);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", handleRoot);
  server.on("/ledOn", handleLEDon);
  server.on("/ledOff", handleLEDoff);
 
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
