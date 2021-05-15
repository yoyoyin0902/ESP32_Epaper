#include <HTTPClient.h>
#incluse <ArduinoJson.h>
#include <WiFi.h>

//StaticJsonDocument<200> json_doc;
//char json_output[100];
//DeserializationError json_error;

const char* ssid = "IVAM_NEW";
const char* password  = "Ming-Long-ccc";
HTTPClient http;

char url[] = "http://opendata2.epa.gov.tw/AQI.json"; //PM2.5的網址


void setup() { 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(100);
  WiFi.begin(ssid, password );
  while(WiFi.status() !=WL_CONNECTED){
    Serial.println("Connrcting to wifi.....");
    delay(500);
    }
  Serial.println("Connected to the network");
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());

}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    
    int httpCode = http.GET();
    Serial.print(" httpCode: ");
    Serial.println(httpCode);
    if(httpCode == HTTP_CODE_OK){
      String payload = http.getString();
      Serial.print(" payload = ");
      Serial.print(payload);
      }
    
    delay(500);
    }

}

void httpSend(String url){
   http.begin(url);
   int httpCode = http.GET();
   Serial.print(" httpCode: ");
   Serial.println(httpCode);
   if(httpCode == HTTP_CODE_OK){
    String rec = http.getString;
    Serial.print(" rec: ");
    Serial.println(rec);
    }
  }



//bool testWifi() {
//  
//  Serial.println("Waiting for Wifi to connect");
//  while (c < 20) {
//    while (WiFi.status() != WL_CONNECTED)
//      return true;
//    delay(500);
//    Serial.print(WiFi.status());
//    c++;
//  }
//  return false;
//}


//
//void setup(){
//  Serial.begin(115200);
//  }
//
//void loop(){
//  Serial.println("hello");
//  delay(100);
//  }
