//++++++++涓插彛鍙橀噺瀹氫箟
String inString = "";  //涓插彛杈撳叆瀛楃涓诧細鍒濆鍖栦负绌�int xxx;                //涓插彛浼犻�杩囨潵鐨剆peed鏁板�

//=========== 鎵嬪姩鎺у埗===========//
void ManualControl()
{
  while (Serial.available() > 0)    //璇诲彇涓插彛杈撳叆锛氭湁杈撳叆鍒欒鍙栦俊鎭�  {
    int inChar = Serial.read();     //璇诲彇淇℃伅锛氳鍙栦负鍗曞瓧绗︼紝鍚庣户闇�皢鍏惰繛璧锋潵鎴愪负瀛楃涓�    if (inChar == '#') 
    {
      xxx = inString.toInt();
      inString="";
      break;
    }
    else
    {
      if (inChar == '*')   {inString =""; break;}
      else    inString += (char)inChar;       //骞朵笖灏嗗叾杩炶捣鏉ワ細濡�1+2+3锛�23
    }    

  }

  Serial.println("Text:"+inString); 

}



