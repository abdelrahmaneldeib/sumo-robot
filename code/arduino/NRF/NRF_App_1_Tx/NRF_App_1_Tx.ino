 // Transmitter Code
 // Pins Connection for Arduino UNO
 /*
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
*/



/* import needed Libraries*/
#include <SPI.h> // Call SPI Library 
#include <nRF24L01.h> // Call NRE Version Library
#include <RF24.h> // RF24 Header File


/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   7
#define CSN_PIN 8

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe
// you can Select Any 40 bit Address Instead of "E8E8F0F0E1"and put LL in the end of the Address


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
/*-----( Declare Variables )-----*/

char out[4] = "sumo";
void setup()
{
  Serial.begin(9600);
  radio.begin();//Intializing NRF24L01 Module
  radio.openWritingPipe(pipe);// For Transmitting Operation, Must OpenWritingPipe
  /*for(int i=2;i<6;i++)
  {
    pinMode(i,INPUT_PULLUP);
  }*/
}

void loop()
{
  /*for(int j=0;j<4;j++)
  {
    out[j]=digitalRead(j+2);
    Serial.print(out[j]);
  }*/
  Serial.println(out);
  radio.write(out,sizeof(out));
}
