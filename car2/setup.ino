
void setup()
{

  pinMode(TrigPin1, OUTPUT);   
  pinMode(EchoPin1, INPUT);   // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
  pinMode(TrigPin2, OUTPUT);   
  pinMode(EchoPin2, INPUT);   // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
  pinMode(TrigPin3, OUTPUT);   
  pinMode(EchoPin3, INPUT);   // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态

//int PEER = 9;       //蜂鸣器
  // 
  pinMode(INA,OUTPUT);
  pinMode(INB,OUTPUT);
//  pinMode(PEER,OUTPUT);

  pinMode(A0,INPUT);    //红外壁障器1
  pinMode(A5,INPUT);    //红外壁障器2



  // 初始化串口通信及连接SR04的引脚
  Serial.begin(9600); 

  myservo.attach(13);  //定义舵机接口数字接口13

  csb(100);      //舵机带动超声波传感器至正位

//  L_run=200;  R_run=200;
 // Go();         //低速前进
}


