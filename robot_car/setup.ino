
int inputPin=4;  // define ultrasonic signal receiver pin  ECHO to D4
int outputPin=5; // define ultrasonic signal transmitter pin  TRIG to D5
void setup()
{
  pinMode(inputPin, INPUT);//鍓嶇疆瓒呭０娉㈡帴鍙ｅ紩鑴� 
   
  // 鍒濆鍖栦覆鍙ｉ�淇″強杩炴帴SR04鐨勫紩鑴�  Serial.begin(9600); 
  
   myservo.attach(13);  //瀹氫箟鑸垫満鎺ュ彛鏁板瓧鎺ュ彛13
   csb(100);            //鑸垫満甯﹀姩瓒呭０娉紶鎰熷櫒鑷虫浣�}





