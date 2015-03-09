//++++++++娑撴彃褰涢崣姗�櫤鐎规矮绠�String inString = "";  //娑撴彃褰涙潏鎾冲弳鐎涙顑佹稉璇х窗閸掓繂顬婇崠鏍﹁礋缁岋拷int xxx;                //娑撴彃褰涙导鐘伙拷鏉╁洦娼甸惃鍓唒eed閺佹澘锟�
//=========== 閹靛濮╅幒褍鍩�==========//
void ManualControl()
{
  while (Serial.available() > 0)    //鐠囪褰囨稉鎻掑經鏉堟挸鍙嗛敍姘箒鏉堟挸鍙嗛崚娆掝嚢閸欐牔淇婇幁锟� {
    int inChar = Serial.read();     //鐠囪褰囨穱鈩冧紖閿涙俺顕伴崣鏍﹁礋閸楁洖鐡х粭锔肩礉閸氬海鎴烽棁锟界殺閸忔儼绻涚挧閿嬫降閹存劒璐熺�妤冾儊娑擄拷    if (inChar == '#') 
    {
      xxx = inString.toInt();
      inString="";
      break;
    }
    else
    {
      if (inChar == '*')   {inString =""; break;}
      else    inString += (char)inChar;       //楠炴湹绗栫亸鍡楀従鏉╃偠鎹ｉ弶銉窗婵★拷1+2+3閿涳拷23
    }    

  }

  Serial.println("Text:"+inString); 

}




