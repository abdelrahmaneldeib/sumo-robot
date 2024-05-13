#include <Ultrasonic.h>
#define IR_FR 3  //front right ir
#define IR_FL 2  //front left ir
#define IR_RT A2  //right top ir
#define IR_LT A3  //left top ir
#define input1 5  //input of
#define input2 6 //      motor
#define input3 9 //         driver
#define input4 10 //             PWM pins
Ultrasonic ultrasonic(A0,A1); //trig,echo
int power = 255;
long duration;
int distance;
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
  distance = ultrasonic.read();
  Serial.print("Distance: ");
  Serial.println(distance);
  //delay(200);
  if(digitalRead(IR_RT) == 0 || digitalRead(IR_LT) == 0)
  {
    backward();
    Serial.println("back");
    return;
  }
  if(distance < 40 && digitalRead(IR_FL) != 1 && digitalRead(IR_FR) != 1)
  {
    forward();
    Serial.println("front");
    at_start = false;
  }
  else if(digitalRead(IR_FL) == 1 && digitalRead(IR_FR) == 0)
  {
    right();
    Serial.println("right");
  }
  else if((digitalRead(IR_FL) == 0 && digitalRead(IR_FR) == 1) || at_start)
  {
    left();
    Serial.println("left");
  }
  else 
  {
    return;
  }
}
