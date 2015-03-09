#include <Servo.h>

Servo fx_servo;  // 定义舵机变量

void fx_csb_setup(){
  Serial.println("fx_servo ready>>>>>" ) ;
  Serial.println();
  fx_csb(100);      //舵机带动超声波传感器至正位

  Serial.println("MyServo init done <<<<<" ) ;
  Serial.println();  
}

void fx_csb(int pos) 
{
  fx_servo.write(pos);  
  delay(250); 			//舵机动作时间
}


