
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>
 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600                                                                                                                                                                                                                           
#define REMOTEXY_ACCESS_PASSWORD "12345"



  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,2,0,0,0,37,0,8,13,1,
  2,1,17,22,22,11,2,26,31,31,
  79,78,0,79,70,70,0,2,1,18,
  59,22,11,2,26,16,125,79,78,0,
  79,70,70,0 };
  
// this structure defines all the variables of your control interface 
struct {

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

#define PIN_SWITCH_1 13
#define PIN_SWITCH_2 12


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer


}
