#include "DayOfYear.h"

int DayOfYear::days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string DayOfYear::monthNames[] = { "January","February","March", "April", "May", "June", "July", "August", "Septempber","October", "November", "December" };
int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

DayOfYear::DayOfYear(int newdayOfMonth, int newmonth)
{

	if (newdayOfMonth < 1 || newdayOfMonth > 31)
		dayOfMonth = 1;
	else
		dayOfMonth = newdayOfMonth;

	if (newmonth < 1 || newmonth > 12)
		month = 1;
	else
		month = newmonth;

	monthName = monthNames[month - 1];

	dayOfYear = 0;
	for (int m = 0; m < month - 1; m++)
		dayOfYear += days_in_month[m];
	dayOfYear += dayOfMonth;
}

void DayOfYear::setDayOfYear(int dayOfYear)
{

	int tempMonth = 0;

	// find the month index (0..11)
	while (daysAtEndOfMonth[tempMonth] < dayOfYear)
		tempMonth++;

	if (dayOfYear - daysAtEndOfMonth[tempMonth - 1] == 0)
		dayOfMonth = days_in_month[tempMonth];
	else
		dayOfMonth = abs(dayOfYear - daysAtEndOfMonth[tempMonth - 1]);

	month = tempMonth + 1;
}

int DayOfYear::getDayOfMonth() const
{
	return dayOfMonth;
}

string DayOfYear::getMonthName() const
{
	return monthNames[month - 1];
}

void DayOfYear::print() const
{
	cout << '\n' << getMonthName() << " " << getDayOfMonth() << "\n";
}

DayOfYear DayOfYear::operator ++()
{
	++dayOfYear;
	if (dayOfYear > 365)
		dayOfYear = 1;
	setDayOfYear(dayOfYear);
	return *this;
}

DayOfYear DayOfYear::operator ++(int n)
{
	DayOfYear temp(dayOfMonth, month);

	dayOfYear++;
	if (dayOfYear > 365)
		dayOfYear = 1;
	setDayOfYear(dayOfYear);
	return temp;
}

DayOfYear DayOfYear::operator --()
{
	--dayOfYear;
	if (dayOfYear < 1)
		dayOfYear = 365;
	setDayOfYear(dayOfYear);
	return *this;
}

DayOfYear DayOfYear::operator --(int)
{
	DayOfYear temp(dayOfMonth, month);

	dayOfYear--;
	if (dayOfYear < 1)
		dayOfYear = 365;
	setDayOfYear(dayOfYear);
	return temp;
}