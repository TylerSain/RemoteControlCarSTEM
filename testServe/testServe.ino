#include "WiFi.h"
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"
 
const char* ssid = "NorthstarMain";
const char* password =  "ste11ar1";
 
AsyncWebServer server(80);
 
void setup(){
  Serial.begin(115200);
 
  if(!SPIFFS.begin()){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
  }
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
 
  server.on("/index", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "data/index.html", "text/html");
  });
 
  server.begin();
}
 
void loop(){}