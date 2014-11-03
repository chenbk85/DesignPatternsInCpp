#include "ClockTime.h"

unsigned ClockTime::GetHour()
{
	return hour;
}

unsigned ClockTime::GetMinute()
{
	return minut;
}

unsigned ClockTime::GetSecond()
{
	return second;
}

void ClockTime::SetTime(unsigned h,unsigned m,unsigned s)
{
	hour = h;
	minut = m;
	second = s;
}

//触发一次通知
void ClockTime::Tick()
{
	//增加一秒时间
	if (second == 59 && minut == 59 && second == 59)
		second = minut = hour = 0;
	else if (second == 59 && minut != 59 && hour != 59)
	{
		second = 0;
		minut++;
	}
	else
		second++;
	//通知
	Notify();
}
