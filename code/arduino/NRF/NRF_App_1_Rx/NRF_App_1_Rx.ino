#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define CE_PIN   7
#define CSN_PIN 8


// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL;
/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
char rec[4];
void setup()  
{
  Serial.begin(9600);
  radio.begin();
  /*for(int j=2;j<6;j++)
  {
    pinMode(j,OUTPUT);
  }*/
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
 
  if ( radio.available() )
  {
    radio.read( rec, sizeof(rec) );
    Serial.println(rec);
    delay(100);
  }
   /*for(int i=0;i<4;i++)
   {
    //Serial.print(rec[i]);
    if(rec[i]==LOW)
    {
      digitalWrite(i+2,HIGH);
    }else digitalWrite(i+2,LOW);
   }
   //Serial.println(); 
    */
}
