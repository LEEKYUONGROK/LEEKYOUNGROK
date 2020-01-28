#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int m_iDay, m_iclock, m_iminute;
public:
	Time(int day, int clock, int minute) { m_iDay = day; m_iclock = clock; m_iminute = minute; }
	friend void operator + (Time tmp);
	void input_clock();
	void Print_clock() { cout << "총 공부 시간 : " << m_iclock << " : " << m_iminute << endl; }
	void Print_Day() { cout << "====== 공부 시간 관리 프로그램 (" << m_iDay << "DAY)=====" << endl; }
	void operator ++() { ++m_iDay; }
	~Time();

	void operator + (Time tmp)
	{
		this->m_iclock += tmp.m_iclock;
		this->m_iminute += tmp.m_iminute;
		while (this->m_iminute >= 60)
		{
			this->m_iclock++;
			this->m_iminute -= 60;
		}
	}
};

