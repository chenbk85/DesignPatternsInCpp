//具体目标（主题）时钟时间
#pragma once
#include<string>
#include "Subject.h"
using std::string;
class ClockTime : public Subject
{
public:
	ClockTime()
		:hour(0), minut(0), second(0){ }
	~ClockTime() = default;

	//内部触发器定期触发通知观察者
	void Tick();
	//获取时间秒数
	unsigned GetSecond();
	//获取分钟数
	unsigned GetMinute();
	//获取小时数
	unsigned GetHour();
	//设置整形时间
	void SetTime(unsigned h, unsigned m, unsigned s);
private:
	unsigned hour;
	unsigned minut;
	unsigned second;
};

