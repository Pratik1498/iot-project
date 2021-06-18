#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ledPin D1 // Red LED
#define pirPin D5 // Input for HC-SR501
int pirValue;  

char auth[] = "RYV_3KTrIuwsp6iph9ECa8zgZgCNKjDl";

char ssid[] = "pratik";
char pass[] = "11111112";

void setup()  
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT); 
void pirSensor()
{
  pirValue = digitalRead(pirPin);
  Blynk.virtualWrite(V0, pirValue);
  pirValue = digitalRead(pirPin);
  digitalWrite(D5, pirValue); 
}

void loop()
{
  Blynk.run();
  pirSensor();
}
