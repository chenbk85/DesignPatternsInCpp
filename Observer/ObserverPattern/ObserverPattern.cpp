//Ö÷º¯Êý
#include <windows.h>
#include "ClockTime.h"
#include "NumberClock.h"
#include "StringClock.h"
int main()
{
	ClockTime sub_clock;
	StringClock s_clock(&sub_clock);
	NumberClock n_clock(&sub_clock);

	sub_clock.Add(&s_clock);
	sub_clock.Add(&n_clock);

	sub_clock.SetTime(10, 10, 10);
	while (true)
	{
		sub_clock.Tick(); 
		s_clock.Print(std::cout);
		n_clock.Print(std::cout);
		Sleep(1000);
	}
	return 0;
}
