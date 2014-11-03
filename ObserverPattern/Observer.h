//观察者抽象基类
#pragma once
class Observer
{
public:
	//拷贝控制成员
	Observer() = default;
	virtual ~Observer() = default;
	//观察者更新自身状态
	virtual void Update() = 0;
};

