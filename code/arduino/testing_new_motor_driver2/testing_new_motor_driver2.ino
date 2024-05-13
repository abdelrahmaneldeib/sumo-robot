#define input1 5  //input of
#define input2 6 //      motor
#define input3 9 //         driver
#define input4 10 //             PWM pins
int power = 100;

void setup() 
{
  Serial.begin(9600); // Starts the serial communication
  pinMode(input1,OUTPUT);
  pinMode(input2,OUTPUT);
  pinMode(input3,OUTPUT);
  pinMode(input4,OUTPUT);
}

void forward()
{
  digitalWrite(input1, HIGH);
  digitalWrite(input2, 0); 
  digitalWrite(input3, HIGH); 
  digitalWrite(input4, 0);
}

void loop() 
{
  forward();
}
