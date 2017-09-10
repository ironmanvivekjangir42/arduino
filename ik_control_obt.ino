#include <Servo.h>
#include <SoftwareSerial.h>
#define number_of_servos 10

int servoPins[] = {23, 25, 27, 29, 31, 43, 34, 37, 39, 41};
Servo servos[number_of_servos];
int servoPosMax[] = {180};
int servoPosMin[] = {0};
int servoPosSafeStart[] = {90};

int bluetoothTx=1;
int bluetoothRx=0;
const int offset=40;
int pos=90;
float B;
float A;

SoftwareSerial bluetooth(bluetoothTx,bluetoothRx);

void setup()
{
  int i;
  for (i=1; i<number_of_servos; i++) 
  {
    servos[i].attach(servoPins[i]);
    servos[i].write(servoPosSafeStart[i]);
  }

  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Connection successful");
  delay(3000);
}

 void loop()
 {
  if(Serial.available()>=0)
  {
    int data=Serial.read();
    switch(data)
    {
      case 'U':FORWARD();break;
      default:break;
    }
  }
  delay(50);
 }
void Servomov( float da)
{
  for (pos=pos; pos <=da; pos +=1)
  {
    servos[1].write(pos);
    delay(5);
  }
  for (pos=pos; pos >=da; pos -=1)
  {
    servos[2].write(pos);
    delay(5);
  }
}

void getangle(float x,float y)
{
  B = degrees(acos((800-x*x-y*y)/800));
  A = 20*tan(x/y)+(B/2);
  Serial.println(A);
  Serial.println(B);
  Servomov(B);
  Servomov(A);
  Servomov(A-B);
}

void FORWARD()
{
  Serial.println("forwd");
  {
    getangle(0,40);
  }
  delay(15);
  {
    getangle(20,20);
  }
  delay(15);
  {
    getangle(20,1);
  }
  delay(15);
}

