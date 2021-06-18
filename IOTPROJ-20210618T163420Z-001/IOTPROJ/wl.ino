#include <Blynk.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
char auth[] = "";
// Your WiFi credentials.
// Set password to &quot;&quot; for open networks.
char ssid[] = "";
char pass[] = ";
int motor = 4; //You can remove this line, it has no use in the program.
const int trigPin =16;
const int echoPin = 5;
// defines variables
long duration;
int distance;
void setup() {
Serial.begin(9600); // Starts the serial communication
Blynk.begin(auth, ssid, pass);
pinMode(16, OUTPUT); // Sets the trigPin as an Output
pinMode(5, INPUT); // Sets the echoPin as an Input
pinMode(4,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay
}
void loop() {
long duration, distance;
digitalWrite(16, LOW); // Added this line
delayMicroseconds(2); // Added this line
digitalWrite(16, HIGH);
delayMicroseconds(10); // Added this line
digitalWrite(16, LOW);


duration = pulseIn(5, HIGH);
distance = (duration/2) / 29.1;
Serial.print(distance);
Serial.println("cm");
Blynk.virtualWrite(V5,distance);
if(distance <= 7)
{
digitalWrite(4,HIGH);
Blynk.notify("Water Level: High");
Serial.println("Notification Sent");
Blynk.email("@gmail.com", "ESP8266 Alert", "Tank is full");
}
else
{
digitalWrite(4,LOW);
}
Blynk.run();
delay(1000);
}
