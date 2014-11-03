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

//����һ��֪ͨ
void ClockTime::Tick()
{
	//����һ��ʱ��
	if (second == 59 && minut == 59 && second == 59)
		second = minut = hour = 0;
	else if (second == 59 && minut != 59 && hour != 59)
	{
		second = 0;
		minut++;
	}
	else
		second++;
	//֪ͨ
	Notify();
}
