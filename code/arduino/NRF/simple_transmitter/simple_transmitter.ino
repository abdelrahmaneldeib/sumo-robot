#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() 
{
  radio.begin();
  Serial.begin(9600);
  radio.openWritingPipe(address); // set the transmitter address
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); 
}

void loop() 
{
  const char text[] = "ST Smart";
  radio.write(text, sizeof(text));
  Serial.println("ST Smart");
  delay(100);
}
