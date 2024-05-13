/*If your serial output has these values then Your nrf module is in working condition :
EN_AA = 0x3f
EN_RXADDR = 0x02
RF_CH = 0x4c
RF_SETUP = 0x03
CONFIG = 0x0f*/
#include <SPI.h>
#include <RF24.h>
#include <printf.h>
RF24 radio(6, 7);  // CE , CSN
byte addresses[][6] = {"1Node", "2Node"};
// CE, CSN pins
void setup() {
radio.begin(); //begin operation of the chip
radio.setPALevel(RF24_PA_LOW); //power gain “higher amplitude longer distance 
//Set Power Amplifier (PA) level and Low Noise Amplifier (LNA) state
radio.startListening(); //Start listening on the pipes opened for reading.
Serial.begin(9600);
printf_begin();
radio.printDetails(); //does nothing if printf is not defined “work 
//with #include <printf.h>
}
void loop() {
// empty
}
