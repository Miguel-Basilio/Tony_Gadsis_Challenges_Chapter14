#ifndef DAY_OF_YEAR_H
#define DAY_OF_YEAR_H

#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
	static int days_in_month[];
	static string monthNames[];
	//static array hold the number of the days after each month
	static int daysAtEndOfMonth[];
private:
	int dayOfYear;
	int dayOfMonth;
	int month;
	string monthName;
public:
	DayOfYear();
	DayOfYear(int dayOfMonth, int month);
	void setDayOfYear(int day);
	int getDayOfMonth() const;
	string getMonthName() const;
	void print() const;
	DayOfYear operator ++();
	DayOfYear operator ++(int);
	DayOfYear operator --();
	DayOfYear operator --(int);

};

#endif // !DAY_OF_YEAR_H
