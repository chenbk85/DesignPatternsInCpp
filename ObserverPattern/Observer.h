//�۲��߳������
#pragma once
class Observer
{
public:
	//�������Ƴ�Ա
	Observer() = default;
	virtual ~Observer() = default;
	//�۲��߸�������״̬
	virtual void Update() = 0;
};

