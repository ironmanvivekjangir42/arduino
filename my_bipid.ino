#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;
Servo myservo9;
Servo myservo10;

int bluetoothTx=1;
int bluetoothRx=0;
const int offset=40;
int pos=90;

SoftwareSerial bluetooth(bluetoothTx,bluetoothRx);

void setup()
{
  myservo1.write(pos);
  myservo1.attach(23);
  myservo2.write(pos);
  myservo2.attach(25);
  myservo3.write(pos);
  myservo3.attach(27);
  myservo4.write(pos);
  myservo4.attach(29);
  myservo5.write(pos);
  myservo5.attach(31);
  myservo6.write(pos);
  myservo6.attach(43);
  myservo7.write(pos);
  myservo7.attach(34);
  myservo8.write(pos);
  myservo8.attach(37);
  myservo9.write(pos);
  myservo9.attach(39);
  myservo10.write(pos);
  myservo10.attach(41);
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
      case 'C':STAND();break;
      case 'L':LEFT();break;
      case 'R':RIGHT();break;
      case 'D':BACK();break;
      case 'a':SIT();break;
      case 'b':UP();break;
      case 'd':DANCE();break;
      default:break;
    }
  }
  delay(50);
 }
 void FORWARD()
 {
  Serial.println("forward");
  {
    myservo1.write(pos-30);
    myservo10.write(pos-25);
    myservo2.write(pos+15);
    myservo3.write(pos+30);
    myservo4.write(pos-15);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
  }
  delay(750);
  {
    myservo2.write(pos-15);
    myservo3.write(pos-30);
    myservo4.write(pos+15);
  }
  delay(750);
  {
    myservo4.write(pos-20);
    myservo3.write(pos+10);
    myservo2.write(pos-30);
    myservo1.write(pos);
    myservo10.write(pos);
  }
  delay(750);
  {
    myservo4.write(pos);
    myservo3.write(pos);
    myservo2.write(pos);
    myservo7.write(pos-10);
    myservo8.write(pos-20);
    myservo9.write(pos-30);
  }
  delay(750);
  {
    myservo1.write(pos+10);
    myservo10.write(pos+30);
    myservo9.write(pos-15);
    myservo8.write(pos-30);
    myservo7.write(pos+15);
  }
  delay(750);
  {
    myservo9.write(pos+15);
    myservo8.write(pos+30);
    myservo7.write(pos-15);
  }
  delay(750);
  {
    myservo1.write(pos);
    myservo10.write(pos);
    myservo7.write(pos+20);
    myservo8.write(pos-10);
    myservo9.write(pos+30);
  }
  delay(705);
  {
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo4.write(pos+10);
    myservo3.write(pos+20);
    myservo2.write(pos+30);
  }
 }

 void STAND()
 {
  Serial.println("stand");
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
 }

 void LEFT()
 {
  Serial.println("left");
  {
    myservo1.write(pos-30);
    myservo10.write(pos-25);
    myservo2.write(pos+15);
    myservo3.write(pos+30);
    myservo4.write(pos-15);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
  }
  delay(750);
  {
    myservo2.write(pos-15);
    myservo3.write(pos-30);
    myservo4.write(pos+15);
  }
  delay(750);
  {
    myservo5.write(pos-30);
    myservo6.write(pos+30);
  }
  delay(750);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
  delay(750);
  {
    myservo1.write(pos+10);
    myservo10.write(pos+30);
    myservo9.write(pos-15);
    myservo8.write(pos-30);
    myservo7.write(pos+15);
  }
  delay(750);
  {
    myservo9.write(pos+15);
    myservo8.write(pos+30);
    myservo7.write(pos-15);
  }
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(750);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
 }
 void RIGHT()
 {
  Serial.println("right");
  {
    myservo1.write(pos+10);
    myservo10.write(pos+30);
    myservo9.write(pos-15);
    myservo8.write(pos-30);
    myservo7.write(pos+15);
  }
  delay(750);
  {
    myservo9.write(pos+15);
    myservo8.write(pos+30);
    myservo7.write(pos-15);
  }
  delay(750);
  {
    myservo5.write(pos-30);
    myservo6.write(pos+30);
  }
  delay(750);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
  delay(750);
  {
    myservo1.write(pos-30);
    myservo10.write(pos-25);
    myservo2.write(pos+15);
    myservo3.write(pos+30);
    myservo4.write(pos-15);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
  }
  delay(750);
  {
    myservo2.write(pos-15);
    myservo3.write(pos-30);
    myservo4.write(pos+15);
  }
  delay(750);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
 }

 void BACK()
 {
  Serial.println("back");
  {
    myservo1.write(pos-30);
    myservo10.write(pos-25);
    myservo2.write(pos+15);
    myservo3.write(pos+30);
    myservo4.write(pos-15);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
  }
  delay(750);
  {
    myservo2.write(pos-15);
    myservo3.write(pos-30);
    myservo4.write(pos+15);
  }
   delay(705);
  {
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo4.write(pos+10);
    myservo3.write(pos+20);
    myservo2.write(pos+30);
    myservo1.write(pos);
    myservo10.write(pos);
  }
  delay(750);
  {
    myservo4.write(pos);
    myservo3.write(pos);
    myservo2.write(pos);
    myservo7.write(pos+20);
    myservo8.write(pos-10);
    myservo9.write(pos+30);
  }
  delay(750);
  {
    myservo1.write(pos+10);
    myservo10.write(pos+30);
    myservo9.write(pos-15);
    myservo8.write(pos-30);
    myservo7.write(pos+15);
  }
  delay(750);
  {
    myservo9.write(pos+15);
    myservo8.write(pos+30);
    myservo7.write(pos-15);
  }
  delay(750);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
  delay(750);
 }
 void SIT()
 {
  Serial.println("sit");
  {
    myservo2.write(pos-15);
    myservo3.write(pos-30);
    myservo4.write(pos+15);
    myservo9.write(pos+15);
    myservo8.write(pos+30);
    myservo7.write(pos-15);
  }
 }

 void UP()
 {
  Serial.println("standing upryt");
  {
    myservo2.write(pos+15);
    myservo3.write(pos+30);
    myservo4.write(pos-15);
    myservo9.write(pos-15);
    myservo8.write(pos-30);
    myservo7.write(pos+15);
  }
 }


 void DANCE()
 {
  Serial.println("dancing");
  {
     myservo1.write(pos-30);
    myservo10.write(pos-25);
    myservo2.write(pos+15);
    myservo3.write(pos+30);
    myservo4.write(pos-15);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
  }
  delay(750);
  {
    myservo2.write(pos-15);
    myservo3.write(pos-30);
    myservo4.write(pos+15);
  }
  delay(500);
  {
    myservo5.write(pos-30);
    myservo6.write(pos+30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo5.write(pos+30);
    myservo6.write(pos-30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo5.write(pos-30);
    myservo6.write(pos+30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo5.write(pos+30);
    myservo6.write(pos-30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
  delay(750);
  {
    myservo1.write(pos+10);
    myservo10.write(pos+30);
    myservo9.write(pos-15);
    myservo8.write(pos-30);
    myservo7.write(pos+15);
  }
  delay(750);
  {
    myservo9.write(pos+15);
    myservo8.write(pos+30);
    myservo7.write(pos-15);
  }
  delay(500);
  {
    myservo5.write(pos-30);
    myservo6.write(pos+30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo5.write(pos+30);
    myservo6.write(pos-30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo5.write(pos-30);
    myservo6.write(pos+30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo5.write(pos+30);
    myservo6.write(pos-30);
  }
  delay(500);
  {
    myservo5.write(pos);
    myservo6.write(pos);
  }
  delay(500);
  {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
  }
 }
 
