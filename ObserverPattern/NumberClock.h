#pragma once
#include <iostream>
#include "Observer.h"
#include "ClockTime.h"
using std::string;
class NumberClock : public Observer
{
public:
	NumberClock(ClockTime* c)
		:own_subject(c){ }
	~NumberClock() = default;
	//重写update
	void Update() override;
	//打印时间
	void Print(std::ostream&);
private:
	//对目标的引用
	ClockTime* own_subject;
	//保存整数时间
	unsigned time;
};

