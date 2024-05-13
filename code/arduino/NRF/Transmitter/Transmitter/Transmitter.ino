#include <Ultrasonic.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
Ultrasonic ultrasonic(A0,A1);
const byte address[6] = "00001";
int power;

void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address); // set the transmitter address
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening(); //Set module as transmitter
  pinMode(A0,OUTPUT);
  pinMode(A1,INPUT);
}

void loop() 
{
  int distance = ultrasonic.read();
  radio.write(&distance, sizeof(distance));
  Serial.println(distance);
  delay(1000);
}
