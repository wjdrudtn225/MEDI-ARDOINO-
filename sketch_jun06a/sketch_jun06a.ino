#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

int val; 
int data;
void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);  
}

void loop()
{
  int dataA = digitalRead(4);
  int dataB = digitalRead(5);
  int dataC = digitalRead(6);
  
  hhh(dataA,dataB,dataC);

  bluetooth.println(data);

}

int hhh(int A, int B, int C){
    if(A == LOW & B == LOW & C == LOW){
      data = 0;
  }else if(A == HIGH & B == LOW & C == LOW){
    data = 1;
  }else if(A == LOW & B == HIGH & C == LOW){
    data = 2;
  }else if(A == HIGH & B == HIGH & C == LOW){
    data = 3;
  }else if(A == LOW & B == LOW & C == HIGH){
    data = 4;
  }else if(A == HIGH & B == LOW & C == HIGH){
    data = 5;
  }else if(A == LOW & B == HIGH & C == HIGH){
    data = 6;
  }else if(A == HIGH & B == HIGH & C == HIGH){
    data = 7;
  }
  Serial.println(data);
  delay(1000);
}
