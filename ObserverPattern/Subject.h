//Ŀ�꣨���⣩�������
#pragma once
#include<list>
#include "Observer.h"
class Subject
{
public:
	//�������Ƴ�Ա
	Subject() = default;
	virtual ~Subject() = default;
	//��һ���۲�����ӽ��۲����б�
	virtual void Add(Observer*);
	//ɾ��һ���۲���
	virtual void Delete(Observer*);
	//֪ͨ���й۲���״̬����
	virtual void Notify();
private:
	//����۲�������
	std::list<Observer*> observers;
};

