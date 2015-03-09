
void setup()
{
  // 初始化串口通信
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);   //前置超声波接口引脚
  pinMode(EchoPin, INPUT);

  pinMode(ESC_P, OUTPUT); //设定有刷电机电调接口引脚 9

  myservo.attach(SERVO_P);  //定义超声波测距舵机接口数字接口13

  fx_servo.attach(FX_SERVO_P);  //定义转向舵机接口数字接口13

  //pinMode(8, OUTPUT);  //左侧置超声波接口引脚
  //pinMode(9, INPUT);

  //pinMode(10, OUTPUT);   //右侧超声波接口引脚
  //pinMode(11, INPUT);
  //


  esc_motor_setup();//初始化电调、电机
  csb_setup();//初始化超声波测距舵机

  fx_csb_setup();//初始化转向舵机


}






