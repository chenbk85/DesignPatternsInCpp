#pragma once
#include "Observer.h"
#include "ClockTime.h"
#include <iostream>
//�ַ�������
using std::string;
class StringClock : public Observer
{
public:
	//���캯����ȡһ��ClockTIme����
	StringClock(ClockTime* c)
		:own_subject(c){ }
	~StringClock() = default;
	//��дUpdate
	virtual void Update() override;
	//��ʾ�ַ���ʱ��
	void Print(std::ostream&);
private:
	//�����Ŀ�������
	ClockTime* own_subject;
	//�����ַ�����ʾ��ʱ��
	std::string time;
};

