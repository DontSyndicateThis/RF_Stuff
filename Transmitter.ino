#include <RCSwitch.h>
int ledKill = 3; 
void setup() {
  // put your setup code here, to run once:
pinMode(ledKill,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledKill, LOW);

  

}
