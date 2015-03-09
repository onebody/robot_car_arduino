//see http://www.docin.com/p-305686520.html

int pulsewidth;//定义脉宽变量
int val;
int val1;
int myangle1;
//下面是servopulse函数部分(此函数意思:也就是說每次都是0.5ms高電平 1.98ms低電平 
// 然後再0.52ms低電平 17ms延時也是低電平)
void servopulse(int sp1,int val1)//定义一个脉冲函数
{
  myangle1=map(val1,0,180,500,2480);
  digitalWrite(sp1,HIGH);//将舵机接口电平至高
  //Serial.print(myangle1,DEC);
  //Serial.print("-----------");
  delayMicroseconds(myangle1);//延时脉宽值的微秒数
  digitalWrite(sp1,LOW);//将舵机接口电平至低
  delay(20-val1/1000);
}
//servopulse函数部分到此结束

//初始化电调、电机
void esc_motor_setup()
{  
  Serial.println("Motor ESC ready>>>>>" ) ;
  Serial.println();

  //看电调说明书，设置油门行程时，一开始需要把遥控器打到最高点。i<=110大概是2杪多
  for(int i=0;i<=110;i++)
  {
    servopulse(ESC_P,150);//引用脉冲函数
  }

  //等电机发出B-B两声后（就是两秒后，大概就是这里了）把油门打到最低点
  for(int i=0;i<=55;i++)
  {
    servopulse(ESC_P,20);//引用脉冲函数
  }

  //后面提示后，就可以控制电机转动了
  for(int i=0;i<=150;i++)
  {
    servopulse(ESC_P,150);//引用脉冲函数
  }
  Serial.println("Motor ESC init done <<<<<" ) ;
  Serial.println();
}

//===========  电机动作  ===============//
//低速前进
void ESC_MGo(){
  esc_motor_run(105,20);
}
//高速前进
void ESC_MGogo(){
  esc_motor_run(120,20);
}

//低速后退
void ESC_MGoBack(){
  esc_motor_run(105,20);
}
//高速后退
void ESC_MGogoBack(){
  esc_motor_run(75,20);
}

//停止
void ESC_MStop(){
  esc_motor_run(0,10);
}

//电机驱动
void esc_motor_run(int value, int time)
{
  for(int i=0;i<=time;i++)//让电机 转动一些时间
  {
    servopulse(ESC_P,105);//引用脉冲函数
  }
  //delay(3000); //延时一段时间
}







