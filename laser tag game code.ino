int mode = 0;
int i = 0;
int x = 0;  //for LEDs -- to pick a random LED
int y = 0;  //for LDRs -- for the corresponding LDR

void setup() {
Serial.begin(9600);
pinMode(2,INPUT);  //LEDs
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);  //touch sensor
pinMode(8,OUTPUT);  //LDRs
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

void LDR (int x, int y)
{
  for (i=0;i<=3000;i++)
  {
    if (digitalRead(y)==LOW)
    {
    Serial.println("Target Hit");
    Serial.println(i);  
    delay(1);
    }
  }
    if (digitalRead(y)==HIGH)
    {
    Serial.println("Game Over");
    digitalWrite(x,LOW);
    }
    //delay(3500);
    mode=0;
}

void loop() {
while (mode == 0)
{
  if (digitalRead(7)==1)
  {
    Serial.println("Starting Game");
    mode=1;
  }
  delay(1000);
}

while (mode == 1)
{
  x=random(8,13);
  y=x-6;
  Serial.println(x);
  delay(1000);
  digitalWrite(x,HIGH);
  LDR(x, y);
}
}
