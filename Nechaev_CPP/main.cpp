#include <iostream>
#include <Windows.h>
using namespace std;

class Time
{
public:
	explicit Time(unsigned int _minutes, unsigned int _hours)
	{
		minutes = _minutes;
		hours = _hours;

		while (minutes >= 60)
		{
			minutes -= 60;
			hours++;
		}
	}

	int GetMinutes()
	{
		return minutes;
	}
	int GetHours()
	{
		return hours;
	}

	Time& operator+(const Time other)
	{
		minutes += other.minutes;
		hours += other.hours;

		while (minutes >= 60)
		{
			minutes -= 60;
			hours++;
		}

		return *this;
	}

	bool operator==(const Time other)
	{
		if (minutes == other.minutes && hours == other.hours) return true;
		else return false;
	}
private:
	unsigned int minutes;
	unsigned int hours;
};

ostream& operator<<(ostream& stream, Time& time)
{
	return stream << time.GetHours() << ":" << time.GetMinutes() << endl;
}

void main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time time1(59, 4);
	Time time2(23, 1);
	Time time3(82, 5);

	cout << time1;
	cout << time2 << endl;

	time1 + time2;
	cout << time1 << endl;

	cout << (time1 == time3);
}