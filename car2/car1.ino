/*
SR04超声波传感器驱动
 串口显示检测距离
 */
// 设定SR04连接的Arduino引脚
 const int TrigPin1 = 2; 
 const int EchoPin1 = 3; 

 const int TrigPin2 = 8; 
 const int EchoPin2 = 9; 

 const int TrigPin3 = 10; 
 const int EchoPin3 = 11; 


float a[6]={};    //存取6个测距数据
float b[6]={};    //存取6个测距数据
float c[6]={};    //存取6个测距数据

float CJ_data_a,CJ_data_b,CJ_data_c;    //筛选后的测距数据


//读取前方超声波测距数据
void read_C()
{
  unsigned int s,t,f;   
  // 产生一个10us的高脉冲去触发TrigPin
  for (s=0;s<6;s++)
  {
    digitalWrite(TrigPin1, LOW); 
    delayMicroseconds(2); 
    digitalWrite(TrigPin1, HIGH); 
    delayMicroseconds(10);
    digitalWrite(TrigPin1, LOW); 
          // 检测脉冲宽度，并计算出距离
    a[s] = pulseIn(EchoPin1, HIGH) / 58.00;
    delay(10);
  }
}

//读取左侧超声波测距数据
void read_L()
{
  unsigned int s,t,f;   
  // 产生一个10us的高脉冲去触发TrigPin

  for (s=0;s<6;s++)
  {
    digitalWrite(TrigPin2, LOW); 
    delayMicroseconds(2); 
    digitalWrite(TrigPin2, HIGH); 
    delayMicroseconds(10);
    digitalWrite(TrigPin2, LOW); 
            // 检测脉冲宽度，并计算出距离
    b[s] = pulseIn(EchoPin2, HIGH) / 58.00;
    delay(10);

  }
}

//读取右侧超声波测距数据
void read_R()
{
  unsigned int s,t,f;   
  // 产生一个10us的高脉冲去触发TrigPin

  for (s=0;s<6;s++)
  {
    digitalWrite(TrigPin3, LOW); 
    delayMicroseconds(2); 
    digitalWrite(TrigPin3, HIGH); 
    delayMicroseconds(10);
    digitalWrite(TrigPin3, LOW); 
            // 检测脉冲宽度，并计算出距离
    c[s] = pulseIn(EchoPin3, HIGH) / 58.00;
    delay(10);

  }
}

//取超声波数据6个，同时进行排序
void Cj_data()
{
  unsigned int i,j,s; 
  float temp1,temp2,temp3;

  for(s=0;s<6;s++)
  {
    for(j=0;j<=5;j++) 
    {
      for (i=0;i<5-j;i++) 
        if (a[i]>a[i+1]) 
        {
          temp1=a[i]; 
          a[i]=a[i+1]; 
          a[i+1]=temp1;
        } 
      }
    }


    for(s=0;s<6;s++)
    {
      for(j=0;j<=5;j++) 
      {
        for (i=0;i<5-j;i++) 
          if (b[i]>b[i+1]) 
          {
            temp2=b[i]; 
            b[i]=b[i+1]; 
            b[i+1]=temp2;
          }
        }
      }

      for(s=0;s<6;s++)
      {
        for(j=0;j<=5;j++) 
        {
          for (i=0;i<5-j;i++) 
            if (c[i]>c[i+1]) 
            {
              temp3=c[i]; 
              c[i]=c[i+1]; 
              c[i+1]=temp3;
            } 
          }
        }
      }

//对6个超声波数据排序掐头去尾取平均
void JL()
      {
        unsigned int i;
        float CJ_temp1,CJ_temp2,CJ_temp3;

        for (i=1;i<5;i++)
        {
        CJ_temp1+=a[i];    //累加
      }
      
   CJ_data_a=CJ_temp1*100/400;      //取4个数据取平均
/////////////////////////////////////////////////
   for (i=1;i<5;i++)
   {
        CJ_temp2+=b[i];    //累加
   }
      
    CJ_data_b=CJ_temp2*100/400;      //取4个数据取平均
    

    for (i=1;i<5;i++)
    {
        CJ_temp3+=c[i];    //累加
    }
      
   CJ_data_c=CJ_temp3*100/400;      //取4个数据取平均
 }

//测定当前距离
void CJ()
 {
  read_C();
  read_L();
  read_R();
  Cj_data();
  JL();
}

//距离判断之后的动作
void JL_Panduan()
{
  if (CJ_data_a<25)   //小于15cm
  {
    //停止
    stop();
  }
  else
  {
    if (CJ_data_a<35)   //小于20cm
    {
      //停止并左右判断，左转或右转
      stop();
      Serial.println("LR");
      delay(200);
      LR_panduan();
    }
    else
    {
      if (CJ_data_a<40)   //小于40cm
      {
        //低速前进
        Go();
//                Serial.print("go - ");
      }
      else 
      {
        //高速前进
        Gogo();
//                Serial.print("gogo - ");
      }
    }
  }
}

//左右距离判断，并进行动作
void LR_panduan()   //舵机角度：0,20右位,70正位,120左位,140
{
  float M1, M2;    //M1右侧距离；M2左侧距离

  csb(40);      //舵机转右40°
  CJ();
  M1=CJ_data_a;   //M1右侧距离

  csb(160);     //舵机转左160°
  CJ();
  M2=CJ_data_a;   //M2左侧距离

  csb(100);     //舵机归正位

  if (((M1+M2)<80)  && (M1<40) && (M2<40))   //间距＜20，后退并左右判断距离再动作
  {
    GoGo_back();
    delay(50);
  }
  else
  {
      if ((M1>M2) && (M1>40)) //M1右侧距离＞M2左侧距离
      {
        if (M1<40)  Diaotu_right();   //M1右侧距离＜35，掉头右转
          else right();       //M1右侧距离＞35，90°右转
      }
        else
        {
           if ((M2>M1) && (M2>40)) //M2左侧距离＞M1右侧距离
           {
              if (M2<40)   Diaotu_left();   //M1右侧距离＜35，掉头左转
              else left();       //M2右侧距离＞35，90°左转
            }
        }
  }

        delay(100);
}

//左右侧超声波判断
void L_R()
{
   Blue_Str();
   // Serial.println(CJ_data_b);
   // Serial.println(CJ_data_c);

  if ((CJ_data_b>10) && (CJ_data_c>10))
  {
    L_run=255;  R_run=255;
//    Gogo();
  }  
    else 
    {
      if ((CJ_data_b<10)  && (CJ_data_c>10)) 
      {
        L_run=120;  R_run=200;
        Da_left();
        delay(10);
//        Go();
      }  
        else
        {
          if ((CJ_data_b>10)  &&  (CJ_data_c<10))  
            {
              L_run=200;  R_run=120;
              Da_right();
              delay(10);
            } 
             else
             {
               L_run=120;  R_run=120;
             }     
        }
    }
}