#define IR_RT A2  //right top ir
#define IR_LT A3  //left top ir
#define IR_RB A4  //right bottom ir
#define IR_LB A5  //left bottom ir
#define IR_FL 2  //front left ir
#define IR_FR 3  //front right ir
#define trig A0  //trig of ultrasonic
#define echo A1  //echo of ultrasonic
#define input1 5  //input of
#define input2 6 //      motor
#define input3 9 //         driver
#define input4 10 //             PWM pins



void setup() 
{
  pinMode(IR_RT,INPUT);
  pinMode(IR_LT,INPUT);
  pinMode(IR_RB,INPUT);
  pinMode(IR_LB,INPUT);
  pinMode(IR_FL,INPUT);
  pinMode(IR_FR,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);

}

void loop() 
{
  

}
