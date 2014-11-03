#include <sstream>
#include "StringClock.h"
#include  "Subject.h"
void StringClock::Update()
{
	//构造一个字符串
	std::ostringstream tem_string;
	tem_string << own_subject->GetHour() << ":" << own_subject->GetMinute() <<
		":" << own_subject->GetSecond();
	//将格式化的字符串写入time
	time = tem_string.str();
}

void StringClock::Print(std::ostream& out)
{
	out << "time in string: " << time << std::endl;
}
