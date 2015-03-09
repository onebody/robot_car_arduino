
int inputPin=4;  // define ultrasonic signal receiver pin  ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin  TRIG to D5
void setup()
{
  pinMode(inputPin, INPUT);//前置超声波接口引脚  
   
  // 初始化串口通信及连接SR04的引脚
  Serial.begin(9600); 
  
   myservo.attach(13);  //定义舵机接口数字接口13
   csb(100);            //舵机带动超声波传感器至正位
}




