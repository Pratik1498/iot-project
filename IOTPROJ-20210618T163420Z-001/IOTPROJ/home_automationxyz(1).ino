#include <ESP8266WiFi.h>
const char* ssid = "pratik";  // Enter SSID here
const char* password = "11111112";  //Enter Password here
// Variable to store the HTTP request
String header;
String LED1State = "off1";
String LED2State = "off2";
const int LED1 = D2;
const int LED2 = D3;
const int LED = D5;
WiFiServer server(80);

void setup()
{
 Serial.begin(115200);
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
  pinMode(LED, OUTPUT);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED, LOW);
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(5000);
 Serial.print(".");
}
// Print local IP address and start web server
 Serial.println("");
 Serial.println("WiFi connected-->");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 delay(5000);
 delay(5000);
 server.begin();
}

void loop()

{
  WiFiClient client = server.available();   
  if (client) 
    {                             // If a new client connects,
    Serial.println("new client connected");          
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected())
      if (client.available()) 
      {             // if there's bytes to read from the client,
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') 
        {                    // if the byte is a newline character
          if (currentLine.length() == 0)
        {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

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
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Cairo; display: inline; margin: 0px auto; text-align: center; background-color: #ADFF2F;}");
            client.println("h1 {color:red;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 35px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #66CDAA;}</style></head>");

          client.println("<svg width=\"300\" height=\"80\"><text fill=\"#00bfbf\" font-family=\"serif\" font-size=\"18\" id=\"svg_1\" stroke=\"#000000\" text-anchor=\"middle\" transform=\"matrix(1.35388 0 0 1.42308 -6.66283 -8.67308)\" x=\"86.5\" xml:space=\"preserve\" y=\"41.5\">    HOME AUTOMATION </text></svg>");
       
            // Web Page Heading
            client.println("<body><h1 >Welcome to home-automation project</h1>");
            client.println("<p>LED1_State: " + LED1State + "</p>"); 
            // If the LED1State is off, it displays the ON button       
            


               if (LED1State=="off1") 
               {
              client.println("<p><a href=\"/LED1/on1\"><button class=\"button\">ON</button></a></p>");
              client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ffffff\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");

               } 
            else
            {
              client.println("<p><a href=\"/LED1/off1\"><button class=\"button button2\">OFF</button></a></p>");
              client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#FF0000\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");
 
            }  
              
            client.println("<p>LED2_State: " + LED2State + "</p>");
            // If the LED2State is off, it displays the ON button       
            if (LED2State=="off2")
            {
              client.println("<p><a href=\"/LED2/on2\"><button class=\"button\">ON</button></a></p>");
              client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#ffffff\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");

            } 
            else
            {
              client.println("<p><a href=\"/LED2/off2\"><button class=\"button button2\">OFF</button></a></p>");
              client.println("<svg width=\"500\" height=\"300\"><ellipse cx=\"258.5\" cy=\"125.5\" fill=\"#FF0000\" rx=\"47\" ry=\"52\" stroke=\"#ffffaa\" stroke-width=\"5\"/><rect fill=\"#cccccc\" height=\"40\" stroke=\"#ffffaa\" stroke-width=\"5\" transform=\"rotate(-0.485546 261 187.5)\" width=\"39\" x=\"241.5\" y=\"167.5\"/></svg>");

            }   
             
            client.println("</body></html>");
            client.println();
            break;
           } 
          else { 
            currentLine = "";
          }
         }
         else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    header = "";
    client.stop();
     
    Serial.println("Client disconnected");
    //    delay(5000);
    
Serial.println("");
  }
