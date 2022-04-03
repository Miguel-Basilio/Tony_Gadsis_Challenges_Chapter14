#ifndef MONTH_H
#define MONTH_H
#include <iostream>
#include <string>
using namespace std;

class Month
{
private:
	string name;
	int monthNumber;
	string uppercase(string n);
	int foundMonthName(string n);
	int increment(int t);
	int decrement(int t);
public:
	Month();
	Month(string n);
	Month(int n);
	void setName(string n);
	string getName() const;
	void setMonthNumber(int n);
	int getMonthNumber() const;
	Month operator ++();
	Month operator ++(int);
	Month operator --();
	Month operator --(int);

	friend istream& operator>>(istream& ins, Month& obj);
	friend ostream& operator<<(ostream& outs, const Month& obj);
};


#endif

