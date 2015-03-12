#include <Servo.h>

Servo myservo;  // 定义舵机变量

void csb_setup() {
  Serial.println("MyServo ready>>>>>" ) ;
  Serial.println();
  csb(120);      //舵机带动超声波传感器至正位

  Serial.println("MyServo init done <<<<<" ) ;
  Serial.println();
}

void csb(int pos)
{
  myservo.write(pos);
  delay(250); 			//舵机动作时间
}

void csb_left() {
  csb_mid();
  csb(170);//舵机转左160°
}

void csb_right() {
  csb_mid();
  csb(40);  //舵机转右40°
}

void csb_mid() {
  csb(120);     //舵机归正位
}




