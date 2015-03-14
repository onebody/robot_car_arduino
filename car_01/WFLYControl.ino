#include<Servo.h>;

//接收机通道 接收引脚
#define AIL1  22   //AIL fuyi
#define ELE2  24   //ELE shengjiang
#define THR3  8   //THR youmen
#define RUD4  28   //RUD fangxiang

//输出至各设备 引脚
#define AIL1_PIN  4   //AIL fuyi
#define ELE2_PIN  5   //ELE shengjiang
#define THR3_PIN  6   //THR youmen
#define RUD4_PIN  7   //RUD fangxiang

unsigned long INAIL;
unsigned long INELE;
unsigned long INTHR;
unsigned long INRUD;
int OUTAIL;
int OUTELE;
int OUTTHR;
int OUTRUD;
Servo AIL;
Servo ELE;
Servo THR;
Servo RUD;

void WFLY_setup()
{
  pinMode(AIL1, 0);
  pinMode(ELE2, 0);
  pinMode(THR3, 0);
  pinMode(RUD4, 0);

  AIL.attach(AIL1_PIN);
  ELE.attach(ELE2_PIN);
  THR.attach(THR3_PIN);
  RUD.attach(RUD4_PIN);
}

//遥控器控制
void WFLY_Control()
{
  INAIL = pulseIn(AIL1, 1);
  INELE = pulseIn(ELE2, 1);
  INTHR = pulseIn(THR3, 1);
  INRUD = pulseIn(RUD4, 1);

  OUTAIL = map(INAIL, 1010, 2007, 47, 144);
  OUTELE = map(INELE, 1010, 2007, 47, 144);
  OUTTHR = map(INTHR, 1010, 2007, 47, 144);
  OUTRUD = map(INRUD, 1010, 2007, 47, 144);

  AIL.write(OUTAIL);
  ELE.write(OUTELE);
  THR.write(OUTTHR);
  RUD.write(OUTRUD);

  Serial.print("AIL=");
  Serial.print(INAIL);
  Serial.print(" ELE=");
  Serial.print(INELE);
  Serial.print(" THR=");
  Serial.print(INTHR);
  Serial.print(" RUD=");
  Serial.print(INRUD);

  delay(5);

}
