#define input1 5  //input of
#define input2 6 //      motor
#define input3 9 //         driver
#define input4 10 //             PWM pins
int pot;

void setup() 
{
  Serial.begin(9600); // Starts the serial communication
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);
  pinMode(2,INPUT);
}

void forward(int pot)
{
  analogWrite(input1, pot);
  analogWrite(input2, 0); 
  analogWrite(input3, pot); 
  analogWrite(input4, 0);
}

void loop() 
{
  pot = analogRead(A0);
  pot = map(pot,0,1023,0,255);
  Serial.println(pot);
  forward(pot);
}
