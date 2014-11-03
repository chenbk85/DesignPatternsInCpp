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
	//��дupdate
	void Update() override;
	//��ӡʱ��
	void Print(std::ostream&);
private:
	//��Ŀ�������
	ClockTime* own_subject;
	//��������ʱ��
	unsigned time;
};

