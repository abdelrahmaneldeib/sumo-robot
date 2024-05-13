#include <Ultrasonic.h>
#define IR_FR 3  //front right ir
#define IR_FL 2  //front left ir
#define IR_RT A2  //right top ir
#define IR_LT A3  //left top ir
#define input1 5  //input of
#define input2 6 //      motor
#define input3 9 //         driver
#define input4 10 //             PWM pins
Ultrasonic ultrasonicR(A0,A1); //trig,echo
Ultrasonic ultrasonicL(A4,A5); //trig,echo
int power = 200;
long duration;
int distanceR;
int distanceL;
bool at_start = true;

void setup() 
{
  Serial.begin(9600); // Starts the serial communication
  pinMode(IR_RT,INPUT);
  pinMode(IR_LT,INPUT);
  pinMode(IR_FL,INPUT);
  pinMode(IR_FR,INPUT);
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);
  delay(5000);
}

void forward()
{
  analogWrite(input1, power*1.1);
  analogWrite(input2, 0); 
  analogWrite(input3, power); 
  analogWrite(input4, 0);
}

void backward()
{
  analogWrite(input1, 0);
  analogWrite(input2, power*1.1); 
  analogWrite(input3, 0); 
  analogWrite(input4, power);
}

void right()
{
  analogWrite(input1, 0);
  analogWrite(input2, power*1.1); 
  analogWrite(input3, power); 
  analogWrite(input4, 0);
}

void left()
{
  analogWrite(input1, power*1.1);
  analogWrite(input2, 0); 
  analogWrite(input3, 0); 
  analogWrite(input4, power);
}

void stopp(){
  analogWrite(input1, 0);
  analogWrite(input2, 0); 
  analogWrite(input3, 0); 
  analogWrite(input4, 0);
}

void loop() 
{
  distanceR = ultrasonicR.read();
  distanceL = ultrasonicL.read();
  Serial.print("DistanceR: ");
  Serial.println(distanceR);
  Serial.print("DistanceL: ");
  Serial.println(distanceL);
  //delay(200);
  if(digitalRead(IR_RT) == 1 || digitalRead(IR_LT) == 1)
  {
    backward();
    Serial.println("back");
    return;
  }
  if((digitalRead(IR_FL) != 1 && digitalRead(IR_FR) != 1) || (distanceR == distanceL))
  {
    forward();
    Serial.println("front");
    at_start = false;
  }
  else if((digitalRead(IR_FL) == 1 && digitalRead(IR_FR) == 0) || (distanceL - distanceR > 3))
  {
    right();
    Serial.println("right");
  }
  else if((digitalRead(IR_FL) == 0 && digitalRead(IR_FR) == 1) || at_start || (distanceR - distanceL > 3))
  {
    left();
    Serial.println("left");
  }
  else 
  {
    return;
  }
}
