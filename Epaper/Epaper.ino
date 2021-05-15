#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>

//StaticJsonDocument<200> json_doc;
//char json_output[100];
//DeserializationError json_error;

const char* ssid = "IVAM_NEW";
const char* password  = "Ming-Long-ccc";

char url[] = "http://opendata2.epa.gov.tw/AQI.json"; //PM2.5的網址

void setup() { 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password );
  Serial.print("Start!!!!");
  
  while(WiFi.status() !=WL_CONNECTED){
    Serial.println(".");
    delay(500);
    }
  Serial.println("Connected to the network");
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());

}

void loop() 
{
  if(WiFi.status() == WL_CONNECTED)
  {
    long rnd = random(1,10);
    HTTPClient client;
    client.begin("http://jsonplaceholder.typicode.com/comments?id="+String(rnd));
    int httpCode = client.GET();
    if(httpCode > 0)
    {
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);

      char json[500];
      payload.replace(" ","");
      payload.replace("\n","");
      payload.trim();
      payload.remove(0,1);
      payload.toCharArray(json,500);

      StaticJsonDocument<200>doc;
      deserializeJson(doc,json);

      int id = doc["id"];
      const char* email = doc["email"];
      Serial.println(String(id) + "-" + String(email)+ "\n");
      client.end();v
    }
    else
    {
      Serial.println("Error on Http request");  
    }
    
  }
  else
  {
    Serial.println("Connection Lost");  
  }
}

//void httpSend(String url){
//   http.begin(url);
//   int httpCode = http.GET();
//   Serial.print(" httpCode: ");
//   Serial.println(httpCode);
//   if(httpCode == HTTP_CODE_OK){
//    String rec = http.getString;
//    Serial.print(" rec: ");
//    Serial.println(rec);
//    }
//  }



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
