//目标（主题）抽象基类
#pragma once
#include<list>
#include "Observer.h"
class Subject
{
public:
	//拷贝控制成员
	Subject() = default;
	virtual ~Subject() = default;
	//将一个观察者添加进观察者列表
	virtual void Add(Observer*);
	//删除一个观察者
	virtual void Delete(Observer*);
	//通知所有观察者状态更新
	virtual void Notify();
private:
	//保存观察者链表
	std::list<Observer*> observers;
};

