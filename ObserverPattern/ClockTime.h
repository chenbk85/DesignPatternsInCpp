//����Ŀ�꣨���⣩ʱ��ʱ��
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

	//�ڲ����������ڴ���֪ͨ�۲���
	void Tick();
	//��ȡʱ������
	unsigned GetSecond();
	//��ȡ������
	unsigned GetMinute();
	//��ȡСʱ��
	unsigned GetHour();
	//��������ʱ��
	void SetTime(unsigned h, unsigned m, unsigned s);
private:
	unsigned hour;
	unsigned minut;
	unsigned second;
};

