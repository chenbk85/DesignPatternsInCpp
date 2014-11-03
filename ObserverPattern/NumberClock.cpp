#include "NumberClock.h"
void NumberClock::Update()
{
	time = own_subject->GetHour() + own_subject->GetMinute() + own_subject->GetSecond();
}

void NumberClock::Print(std::ostream& out)
{
	out << "time in number: " << time << std::endl;
}
