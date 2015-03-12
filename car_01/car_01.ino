
const int ESC_P = 9; //设定有刷电机电调接口引脚
const int SERVO_P = 13;//超声波测距舵机

const int FX_SERVO_P = 12;//转向舵机
const int TrigPin = 2;
const int EchoPin = 3;


String inString = "";  //串口输入字符串：初始化为空
int blue_start = 0;    //蓝牙启动标志：若为 1 ，则由蓝牙控制接管。初始化为 0
int xxx;                //串口传送过来的speed数值
//===========  蓝牙通讯控制  ==============//
void Blue_Str()
{
  while (Serial.available() > 0)    //读取串口输入：有输入则读取信息
  {
    int inChar = Serial.read();     //读取信息：读取为单字符，后继需将其连起来成为字符串
    if (inChar == '#')
    {
      xxx = inString.toInt();
      inString = "";
      break;
    }
    else
    {
      if (inChar == '*')  {
        inString = "";
        break;
      }
      else    inString += (char)inChar;       //并且将其连起来：如 1+2+3＝123
    }
  }

  if (inString == "go")             //如果输入信息为 go，则低速前行
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
    //ESC_MGo();
  }

  if (inString == "mg")
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
    //ESC_MGogo();
  }


  if (inString == "stop")
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
    //ESC_MStop();
  }

  if (inString == "left")
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
  }

  if (inString == "right")
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
  }

  if (inString == "back")
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
    //ESC_MGoBack();
  }

  if (inString == "mb")
  {
    Serial.print(inString);
    Serial.println();
    inString = "";
    //ESC_MGogoBack();
  }


}


//大右转
void Da_right()
{
  Serial.println("car Da_right <<<<<" ) ;
  Serial.println();
  fx_csb(60);//舵机归正位
  fx_csb(0);//舵机转右40°
  ESC_MGo();
  delay(1000);
  fx_csb(60);//舵机归正位
}


//大左转
void Da_left()
{
  Serial.println("car Da_left <<<<<" ) ;
  Serial.println();
  fx_csb(60);//舵机归正位
  fx_csb(160);//舵机转左60°
  ESC_MGo();
  delay(1000);
  fx_csb(60);//舵机归正位
}

//左转弯
void left()
{
  Serial.println("car left <<<<<" ) ;
  Serial.println();
  fx_csb(60);//舵机归正位
  fx_csb(160);//舵机转左160°
  ESC_MGo();
  delay(550);
  fx_csb(60);//舵机归正位
}

//右转弯
void right()
{

  Serial.println("car right <<<<<" ) ;
  Serial.println();
  fx_csb(60);//舵机归正位
  fx_csb(0);//舵机转右40°
  ESC_MGo();
  delay(550);
  fx_csb(60);//舵机归正位
}

//左转弯掉头
void Diaotou_left()
{
  Serial.println("car Diaotou_left <<<<<" ) ;
  Serial.println();
  fx_csb(60);//舵机归正位
  fx_csb(160);//舵机转左160°
  ESC_MGo();
  delay(1700);
  fx_csb(60);//舵机归正位
}


//右转弯掉头
void Diaotou_right()
{
  Serial.println("car Diaotou_right <<<<<" ) ;
  Serial.println();
  fx_csb(60);//舵机归正位
  fx_csb(0);//舵机转右40°
  delay(1700);
  fx_csb(60);//舵机归正位
}












