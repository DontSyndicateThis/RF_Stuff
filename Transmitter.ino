#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int button = 4; //Sets button to pin digital pin 4. 
void setup() 
{

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);

  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}

void loop() 
{
  if (mySwitch.available()) { //If mySwitch is not currently transmitting or recieving it will act as a reciever
    
    Serial.print("Transmitter Received ");
    Serial.print( mySwitch.getReceivedValue()); //Prints the recieved message to the Serial Monitor 
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() ); //Prints the length of the message to the Serial Monitor
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() ); //Prints the protocol that the message was sent with 
    delay(2000);
    mySwitch.resetAvailable();
}
  if (digitalRead(button) == HIGH) //If the button is pushed 
  {
  
  mySwitch.send("111111111111111111111111"); //Sends message in binary 
  delay(1000); //Delay to make sure the message has time to be sent fully

  }
   
}
