
int ACWATERPUMP = 4; //You can remove this line, it has no use in the program.

const int trigPin =16;
const int echoPin = 5;
// defines variables
long duration;
int distance;

void setup() {
 
pinMode(16, OUTPUT); // Sets the trigPin as an Output
pinMode(5, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
  pinMode(4,OUTPUT); //Set pin 13 as OUTPUT pin, to send signal to relay
}

void loop() {


  long duration, distance;
  digitalWrite(16, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(16, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(16, LOW);
  duration = pulseIn(5, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  if(distance <= 5)
  {
  digitalWrite(4,HIGH); //if soil moisture sensor provides LOW value send LOW value to relay
  }
  else
  {
  digitalWrite(4,LOW); //if soil moisture sensor provides HIGH value send HIGH value to relay
  }
  delay(400); //Wait for few second and then continue the loop.
}
