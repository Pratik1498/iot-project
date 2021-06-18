#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
String header;
String LED1State = "off1";
String LED2State = "off2";
const int LED1 = D0;
const int LED2 = D1;
const char* ssid = "pratik";
const char* password = "11111112";

void setup () {

  Serial.begin(115200); // Start the serial monitor.
  
  pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, LOW);
  
  delay(10); // Give it a moment.


 // pinMode(2, OUTPUT); // Set GPIO2 as an OUTPUT.
  //digitalWrite(2, 0); // Start off.

  // Connect to WiFi network:
  Serial.println("Hello Digital Craft");
  Serial.println("Connecting ");
  WiFi.begin(ssid, password);

  // Show ... until connected:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  // Print the IP address of the device:
  Serial.println(WiFi.localIP());

}

void loop() {

  // Verfiy WiFi is connected:
  if (WiFi.status() == WL_CONNECTED) 

   HTTPClient http;  // Object of the class HTTPClient.

    http.begin("http://dockit.org/nodemcu/data.txt");  // Request destination.
    int httpCode = http.GET(); // Send the request.
 char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (header.indexOf("GET /LED1/on1") >= 0)
            {
              Serial.println("LED1 on1");
              LED1State = "on1";
              digitalWrite(LED1, HIGH);
            } else if (header.indexOf("GET /LED1/off1") >= 0) {
              Serial.println("LED1 off1");
              LED1State = "off1";
              digitalWrite(LED1, LOW);
            } 
           else if (header.indexOf("GET /LED2/on2") >= 0) 
          {
              Serial.println("LED2 on2");
              LED2State = "on2";
              digitalWrite(LED2, HIGH);
          }
          else if (header.indexOf("GET /LED2/off2") >= 0) 
          
         {
              Serial.println("LED2 off2");
              LED2State = "off2";
              digitalWrite(LED2, LOW);
          } 
            
    if (httpCode > 0) { //Check the returning code

      Serial.println("We got a repsonse!");
      String payload = http.getString();   // Get the text from the destination (1 or 0).
      Serial.println(payload); // Print the text.
      digitalWrite(2, payload.toInt()); // Send the payload value to the pin.

    }else{

      Serial.println("Something baaaaaaad happened!");

    }

    http.end();   //Close connection

  }

  delay(1000);    //Send a request every 30 seconds

}
