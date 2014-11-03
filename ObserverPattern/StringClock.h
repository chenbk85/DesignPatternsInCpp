#pragma once
#include "Observer.h"
#include "ClockTime.h"
#include <iostream>
//字符串表类
using std::string;
class StringClock : public Observer
{
public:
	//构造函数读取一个ClockTIme引用
	StringClock(ClockTime* c)
		:own_subject(c){ }
	~StringClock() = default;
	//重写Update
	virtual void Update() override;
	//显示字符串时间
	void Print(std::ostream&);
private:
	//保存对目标的引用
	ClockTime* own_subject;
	//保存字符串表示的时间
	std::string time;
};

