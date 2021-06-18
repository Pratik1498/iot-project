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
  { 255,0,0,4,0,110,0,8,13,1,
  129,0,2,2,18,6,17,80,97,114,
  107,105,110,103,32,77,97,110,97,103,
  101,109,101,110,116,32,0,65,36,10,
  16,9,9,65,36,11,38,9,9,65,
  36,10,59,9,9,65,36,10,81,9,
  9,129,0,28,16,18,6,111,83,108,
  111,116,32,49,0,129,0,28,40,18,
  6,111,83,108,111,116,32,50,0,129,
  0,28,60,18,6,111,83,108,111,116,
  32,51,0,129,0,28,82,18,6,111,
  83,108,111,116,32,52,0 };
  
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



void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer


}
