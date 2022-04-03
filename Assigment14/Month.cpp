#include "Month.h"

const string months[13] = { "unknown", "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int Month::decrement(int t)
{
	int temp = t;
	--temp;

	if (temp < 1)
		temp = 12;

	return temp;

}

Month Month::operator --()
{
	setMonthNumber(decrement(monthNumber));
	return *this;
}

Month Month::operator --(int)
{
	Month m(monthNumber);

	setMonthNumber(decrement(monthNumber));

	return m;
}


int Month::increment(int t)
{
	int temp = t;
	++temp;

	if (temp > 12)
		temp = 1;

	return temp;

}

Month Month::operator ++()
{
	setMonthNumber(increment(monthNumber));
	return *this;
}

Month Month::operator ++(int)
{
	Month m(monthNumber);

	setMonthNumber(increment(monthNumber));

	return m;
}

int Month::foundMonthName(string n)
{
	for (int c = 1; c <= 12; c++)
		if (months[c] == uppercase(n))
			return c;
	return 0;
}
string Month::uppercase(string n)
{
	for (unsigned int c = 0; c < n.length(); c++)
		if (c == 0)
			n[c] = toupper(n[c]);
		else
			n[c] = tolower(n[c]);
	return n;
}

Month::Month()
{
	setMonthNumber(1);
}

Month::Month(string n)
{
	setName(n);
}

void Month::setName(string n)
{
	int temp = foundMonthName(n);
	name = months[temp];
	monthNumber = temp;
}

string Month::getName() const
{
	return name;
}

Month::Month(int n)
{
	setMonthNumber(n);
}

void Month::setMonthNumber(int n)
{
	if (n >= 1 && n <= 12)
	{
		name = months[n];
		monthNumber = n;
	}
	else
	{
		name = months[0];
		monthNumber = 0;
	}
}

int Month::getMonthNumber() const
{
	return monthNumber;
}

istream& operator>>(istream& ins, Month& obj)
{
	int temp;
	ins >> temp;
	obj.setMonthNumber(temp);
	return ins;
}

ostream& operator<<(ostream& outs, const Month& obj)
{
	outs << obj.getName() << "(" << obj.getMonthNumber() << ")";
	return outs;
}

