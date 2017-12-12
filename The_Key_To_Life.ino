#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int button = 8; //Button high or low is set to digital pin 8
int orange = 4; //Led on or off is set to pin 4
long value; // Value is declared as long since it is a binary number being converted to decimal therefore it will get truncated as an int
void setup()
{

  Serial.begin(9600);
 pinMode(orange, OUTPUT); //Sets digital pin 4 as output
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

 //long binary = 0, i =1;
// int remainder;

  if (mySwitch.available()) { //If switch is not currently recieving or transmitting it will act as a reciever
    digitalWrite(orange,HIGH); //When a messaged is recieved the orange leds are turned on
    delay(200);//Sufficient delay to see led is on
    Serial.print("Sniffer Received ");
    Serial.print( mySwitch.getReceivedValue() ); //Prints the recieved message to the console in decimal (default for RC_Switch
    value = mySwitch.getReceivedValue(); //Sets recieved value equal to the long defined before 
   
  
 //Serial.print(value);
 //Serial.print(" / ");
/*while(value !=0){
  remainder = value%2;
  value=value/2;
  binary=binary+(remainder*i);
  i=i*10;
}
*/
//Serial.print(binary);
  
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );//Prints the length of the message to the Serial Monitor
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );  //Prints the protocol that the message was sent with
   
  
    

    mySwitch.resetAvailable(); //Resets availibility of switch
    
  }
    if(digitalRead(button)==HIGH) //If the button is pressed 
      {
      mySwitch.send(value,24); //Send value as an integer of 24 bits 
      delay(200); //Ensures sufficient time has passed for message to send 
      value=0; //Resets value mostly a debugging test
      }
  
  /*
  if (digitalRead(button) == HIGH)
{
    Same switch as above, but using binary code
   mySwitch.send(value, 24);

    delay(2000);
  }
  */
  digitalWrite(orange,LOW); //Turn orange led off
}




