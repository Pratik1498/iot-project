/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.3.5 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.3.1 or later version;
     - for iOS 1.3.5 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>
#include <Servo.h>
// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "Rahul"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "12345"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,0,0,4,0,54,0,8,13,1,
  129,0,2,2,18,6,17,80,97,114,
  107,105,110,103,32,77,97,110,97,103,
  101,109,101,110,116,32,0,65,36,10,
  16,9,9,65,36,11,38,9,9,65,
  36,10,59,9,9,65,36,10,81,9,
  9 };
  
// this structure defines all the variables of your control interface 
struct {

    // output variable
  uint8_t led_1_r; // =0..255 LED Red brightness 
  uint8_t led_2_r; // =0..255 LED Red brightness 
  uint8_t led_3_r; // =0..255 LED Red brightness 
  uint8_t led_4_r; // =0..255 LED Red brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


Servo servo1;
Servo servo2;

const int analogInPin1 = A0;
const int analogInPin2 = A1;
const int analogInPin3 = A2;
const int analogInPin4 = A3;

const int servo_sensor1 = A4;
const int servo_sensor2 = A5;

int led = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;

const int servo_1 =6;
const int servo_2 =7;

int value_1 =0;
int value_2 =0;

void setup() 
{
  RemoteXY_Init (); 
  // TODO you setup code
   pinMode (analogInPin1,INPUT);
    pinMode (analogInPin2,INPUT);
    pinMode (analogInPin3,INPUT);
    pinMode (analogInPin4,INPUT);
  
  pinMode(servo_sensor1,INPUT);
  pinMode(servo_sensor2,INPUT);
  
  servo1.attach(servo_1);
  servo2.attach(servo_2);

    pinMode (led,OUTPUT);
    pinMode (led1,OUTPUT);
    pinMode (led2,OUTPUT);
  
}

void loop() 
{ 
  RemoteXY_Handler ();

  
  // TODO you loop code
  // use the RemoteXY structure for data transfer

value_1 = analogRead(servo_sensor1);
  value_2 = analogRead(servo_sensor2);

      // servo 1 code //
      
  {
    if (analogRead(A4)<500)
      {
        servo1.write(90);
        delay(3000);
      }
     
  }
  
  if (analogRead(A4)>500)
      {
        servo1.write(0);
        delay(60);
      }

        // servo 2 code //

  {
    if (analogRead(A5)<500)
      {
        servo2.write(90);
        delay(3000);
      }
     
  }
  
  if (analogRead(A5)>500)
      {
        servo2.write(0);
        delay(60);
      }


      // Parking Slot 1 IR & Led
 if (analogRead(A0)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led, HIGH);
                 
                    RemoteXY.led_1_r = 255;   // then turn on red light
                  
    
                 
               }

          else if (analogRead(A0)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led, LOW);
                 RemoteXY.led_1_r = 0;
               }
               
  // Parking Slot 2 IR & Led
 if (analogRead(A1)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led1, HIGH);
                  RemoteXY.led_2_r = 255;
               }

          else if (analogRead(A1)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led1, LOW);
                 RemoteXY.led_2_r = 0;
               }

  // Parking Slot 3 IR & Led
 if (analogRead(A2)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led2, HIGH);
                  RemoteXY.led_3_r = 255;
               }

          else if (analogRead(A2)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led2, LOW);
                 RemoteXY.led_3_r = 0;
               } 

  // Parking Slot 4 IR & Led
 if (analogRead(A3)<500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led3, HIGH);
                  RemoteXY.led_4_r = 255;
               }

          else if (analogRead(A3)>500)  // if the IR sensor value is < 500 then the motor will start rotating     
               {
                 digitalWrite(led3, LOW);
                 RemoteXY.led_4_r = 0;
               }
}
