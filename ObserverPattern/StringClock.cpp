#include <sstream>
#include "StringClock.h"
#include  "Subject.h"
void StringClock::Update()
{
	//����һ���ַ���
	std::ostringstream tem_string;
	tem_string << own_subject->GetHour() << ":" << own_subject->GetMinute() <<
		":" << own_subject->GetSecond();
	//����ʽ�����ַ���д��time
	time = tem_string.str();
}

void StringClock::Print(std::ostream& out)
{
	out << "time in string: " << time << std::endl;
}
