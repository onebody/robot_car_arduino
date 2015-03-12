//see http://www.docin.com/p-305686520.html

#include <Servo.h>

int pulsewidth;//定义脉宽变量
int val;
int val1;
int myangle1;

Servo powerServo[4];

//双向电调（有正、反转和刹车），标准1.5ms是0点，1ms是反向油门最大（100%油门），用于刹车或反转；2ms正向油门最大（100%油门），用于正转。
void servopulse(int sp1, double val1, int time) //定义一个脉冲函数
{
  //  double T = 2000; // 一个周期的微秒值
  powerServo[0].writeMicroseconds(val1);
  //  delayMicroseconds(T);//延时脉宽值的微秒数
  delay(time);
  powerServo[0].writeMicroseconds(1500); //刹车
}

//初始化电调、电机
void esc_motor_setup() {
  Serial.println("Motor ESC ready>>>>>" ) ;
  Serial.println();
  powerServo[0].attach(ESC_P);

  //设置油门行程时，一开始需要把遥控器打到最高点。i<=110大概是2杪多
  //正向油门最大
  esc_motor_run(ESC_P, 2000);

  //刹车
  esc_motor_run(ESC_P, 1500);

  //反向油门最大
  esc_motor_run(ESC_P, 1000);
  Serial.println("Motor ESC init done <<<<<" ) ;
  Serial.println();
}

//===========  电机动作  ===============//
//低速前进
void ESC_MGo() {
  Serial.println("Motor ESC MGo <<<<<" ) ;
  Serial.println();
  esc_motor_run(ESC_P, 1600);
}
//高速前进
void ESC_MGogo() {
  Serial.println("Motor ESC MGogo <<<<<" ) ;
  Serial.println();
  esc_motor_run(ESC_P, 1800);
}

//低速后退
void ESC_MGoBack() {
  Serial.println("Motor ESC MGoBack <<<<<" ) ;
  Serial.println();
  esc_motor_run(ESC_P, 1400);
}
//高速后退
void ESC_MGogoBack() {
  Serial.println("Motor ESC MGogoBack <<<<<" ) ;
  Serial.println();
  esc_motor_run(ESC_P, 1200);
}

//停止
void ESC_MStop() {
  esc_motor_run(ESC_P, 1500);
}

//电机驱动
void esc_motor_run(int sp1, int value)
{
  // servopulse(sp1, value, 3000); //引用脉冲函数
  //delay(3000); //延时一段时间
}







