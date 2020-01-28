#include "Time.h"

void Time::input_clock()
{
	cout << "시간을 입력하세요 : ";
	cin >> m_iclock;
	cout << "분을 입력하세요 : ";
	cin >> m_iminute;;
}
Time::~Time()
{
}
