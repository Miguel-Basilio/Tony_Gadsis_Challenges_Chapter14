#pragma once
#include <array>
#include <iostream>
#include <string>
using std::string;

using namespace std;

class Date
{
private:
    static const array<int, 13> daysPerMonth;            // Holds number of days per month
    static const array<string, 13> monthNames;        // Holds month names (JAN -> DEC)

    int month;                        // Holding the month
    int day;                            // Holding the day 
    int year;                        // Holding the year
    int difference;                // Holding the difference in days between two dates

public:
    Date() { }
    Date(int, int, int);            // Constructor accepting arguments
    ~Date() {}                        // Destructor

    void setYear(int);
    void setMonth(int);
    void setDay(int);
    bool isLeapYear() const;
    void helpIncrement();
    void helpDecrement();
    int calcJulianDate(const Date&);
    void printFormatOne();
    void printFormatTwo();
    void printFormatThree();

    int getYear() const
    {
        return year;
    }

    int getMonth() const
    {
        return month;
    }

    int getDay() const
    {
        return day;
    }

    int getDifference() const
    {
        return difference;
    }

    // Overloaded operator functions
    Date& operator ++();                        // Prefix ++
    Date operator ++(int);                    // Postfix ++
    Date& operator --();                        // Prefix --
    Date operator --(int);                    // Postfix --
    Date operator -(const Date&);        // Binary -
    bool operator >(const Date&);        // Greater 

    // Friends
    friend istream& operator >> (istream&, Date&);
    friend ostream& operator << (ostream&, const Date&);
};

