void loop()
{
  int f; 
  int Sensor_L=A0;  //前左红外避障器
  int Sensor_R=A5;  //前右红外避障器

//  Sensor_L = Sensor_R=1;

  Blue_Str();

  while (start==1)
  {  
     Blue_Str();

     if (digitalRead(Sensor_L) && digitalRead(Sensor_R))    //前方无障碍
      {
         Blue_Str();
        CJ();             //超声波测距
         Blue_Str();
        JL_Panduan();     //距离判断并动作
         Blue_Str();
        L_R();
       }
      else 
        {
          GoGo_back();
           Blue_Str();
          delay(300);
          stop();
           Blue_Str();
          LR_panduan();
           Blue_Str();
          L_R();
           Blue_Str();
          
        }
  }
}