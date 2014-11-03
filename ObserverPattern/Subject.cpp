#include "Subject.h"

void Subject::Add(Observer* obs)
{
	observers.push_back(obs);
}

void Subject::Delete(Observer* obs)
{
	for (auto iter = observers.cbegin(); iter != observers.cend();iter++)
		if (*iter == obs)
			observers.erase(iter);
}

void Subject::Notify()
{
	for (auto o : observers)
		o->Update();
}
