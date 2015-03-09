
String inString = "";    //输入字符串
int L_run,  R_run;  //驱动运行值
int start=0;      //启动标志


void Blue_Str()
{
	while (Serial.available() > 0)
	{
		int inChar = Serial.read();

		inString += (char)inChar; 

		if (inChar == '\n') 
		{
			inString = ""; 
		}
	}

	if (inString=="start-H") 	
	{
		L_run=250;  R_run=250;
//		Serial.println("Gogo1");
		Gogo();
		inString = "";
		start=1;
	}

	if (inString=="start-L") 	
	{
		L_run=150;  R_run=150;
//		Serial.println("Go1");
		Go();
		inString = "";
		start=1;
	}	

	if (inString=="stop")
	{
		Serial.println("stop1");
		stop();
		inString = "";
		start=0;
	}

	if (inString=="left")
	{
//		Serial.println("left1");
		left();
		inString = "";
	}

	if (inString=="right")
	{
//		Serial.println("right1");
		right();
		inString = "";
	}	

	if (inString=="back")
	{
//		Serial.println("back1");
		GoGo_back();
		inString = "";
	}	

	if (inString=="D-left")
	{
		L_run=120;  R_run=200;
//		Serial.println("DA_left1");
		Da_left();
		inString = "";
	}	

}


