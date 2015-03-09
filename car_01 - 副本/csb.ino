#include <Servo.h>

Servo myservo;  // 定义舵机变量

void csb_setup(){
  Serial.println("MyServo ready>>>>>" ) ;
  Serial.println();
  csb(100);      //舵机带动超声波传感器至正位

  Serial.println("MyServo init done <<<<<" ) ;
  Serial.println();  
}

void csb(int pos) 
{
  myservo.write(pos);  
  delay(250); 			//舵机动作时间
}




