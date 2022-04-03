#include "Date.h"
#include <array>
using std::array;

#include <iostream>
using std::cout;

#include <string>
using std::string;

// Initializes the daysPerMonth array with the days per month
const array<int, 13> Date::daysPerMonth{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Initializes the monthNames array with the names of the months of the year
const array<std::string, 13> Date::monthNames{ "", "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };

enum Months { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };


   //constructor accepts arguments for year, month and day.

Date::Date(int yyyy, int mm, int dd)
{
    setYear(yyyy);
    setMonth(mm);
    setDay(dd);
}

/* **********************************************************
            Date::setYear() : int
    If the argument passed to the setYear function is greater
    than or equal to 1900 and less than or equal to 2020, it
    is copied into the 'year' member. If it is not, the value
    of year is set to 1900.
    ********************************************************** */

void Date::setYear(int yyyy)
{
    yyyy >= 1900 && yyyy <= 2022 ? year = yyyy : year = 1900;
}

/* **********************************************************
            Date::setMonth() : int
    If the argument passed to the setMonth function is greater
    than or equal to JANUARY and lower than or equal to
    DECEMBER, it is copied into the member variable month. If
    it is not, the month value is set to 1.
    ********************************************************** */

void Date::setMonth(int mm)
{
    mm >= JANUARY && mm <= DECEMBER ? month = mm : month = 1;
}

/* **********************************************************
            Date::setDay() : int
    If the argument passed to the setDay function is greater
    than 1 and less than or equal to daysPerMonth (ex: April
    has 30 days), it is assigned to the day member variable.
    If it is a leap year, days is set to 29, else 28 is set.
    If neither of these conditions are met, day is set to 1.
    Else, if the value dd is in the valid range, its value is
    assigned ot the day member variable.
    ********************************************************** */

void Date::setDay(int dd)
{
    if (month == FEBRUARY && isLeapYear() && dd == 29)
    {
        day = 29;
    }
    else if (month == FEBRUARY && dd > daysPerMonth[getMonth()])
    {
        day = 28;
    }

    else if (dd < 1 || dd > daysPerMonth[getMonth()])
    {
        day = 1;
    }
    else
    {
        day = dd;
    }
}

/* **********************************************************
            Date::isLeapYear()
    This function determines whether a year is a leap year. If
    it is true is returned, else it returns false.
    ********************************************************** */

bool Date::isLeapYear() const
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    return false;
}

/* **********************************************************
            Date::helpIncrement()
    This helper function determines whether the day, day and
    month, or day month and year values should be incremented.
    ********************************************************** */

void Date::helpIncrement()
{
    if (day > daysPerMonth[month] && month < DECEMBER)
    {
        if (day >= 30)
        {
            month++;
            day = 1;
        }
        else if (month == FEBRUARY && isLeapYear())
        {
            day = 29;
        }
        else if (month == FEBRUARY && !isLeapYear())
        {
            month++;
            day = 1;
        }
    }

    if (month == DECEMBER && day > 31)
    {
        year++;
        month = 1;
        day = 1;
    }
}

/* **********************************************************
            Date &Date::operator++() : Prefix ++
   ********************************************************** */

Date& Date::operator++()
{
    ++day;
    helpIncrement();
    return *this;
}

/* **********************************************************
            Date Date::operator++(int) : Postfix ++
   ********************************************************** */

Date Date::operator++(int)
{
    Date tempDate(year, month, day);

    day++;
    helpIncrement();

    return tempDate;
}

/* **********************************************************
            Date::helpDecrement()
    This helper function determines whether year or month
    should be decremented. If a condition is met, the day and
    month member variables are set accordingly.
    ********************************************************** */

void Date::helpDecrement()
{
    if (month == JANUARY)
    {
        month = DECEMBER;
        day = 31;
        year--;
    }
    else
    {
        month--;

        if (daysPerMonth[month] == 31)
        {
            day = 31;
        }
        else if (daysPerMonth[month] == 30)
        {
            day = 30;
        }
        else if (month == FEBRUARY && isLeapYear())
        {
            day = 29;
        }
        else
        {
            day = 28;
        }
    }
}

/* **********************************************************
            Date Date::operator--() : Prefix --
   ********************************************************** */

Date& Date::operator--()
{
    if (day > 1)
    {
        --day;
    }
    else
    {
        helpDecrement();
    }

    return *this;
}

/* **********************************************************
            Date Date::operator--(int) : Postfix --
   ********************************************************** */

Date Date::operator--(int)
{
    Date tempDate(year, month, day);

    if (day > 1)
    {
        day--;
    }
    else
    {
        helpDecrement();
    }

    return tempDate;
}

/* **********************************************************
            Date::calcJulianDate() : const Date &
    This function calculates the Julian dates for two date
    objects. (The formula used for calculation can be found in
    the Wiki-Article: Julian day)
    ********************************************************** */

int Date::calcJulianDate(const Date& dateOne)
{
    int julianDate = (1461 * (dateOne.year + 4800 + (dateOne.month - 14) / 12)) / 4 +
        (367 * (dateOne.month - 2 - 12 * ((dateOne.month - 14) / 12))) / 12 -
        (3 * ((dateOne.year + 4900 + (dateOne.month - 14) / 12) / 100)) / 4 +
        (dateOne.day - 32075);

    return julianDate;
}

/* **********************************************************
            bool Date::operator >() : Greater
    ********************************************************** */

bool Date::operator >(const Date& right)
{
    if (year > right.year)
    {
        return true;
    }

    if (year == right.year && month > right.month)
    {
        return true;
    }

    if (year == right.year && month == right.month && day > right.day)
    {
        return true;
    }

    return false;
}

/* **********************************************************
            Date Date::operator -() : Binary -
    ********************************************************** */

Date Date::operator-(const Date& right)
{
    Date temp;
    Date tempOne = right;

    temp.year = year;
    temp.month = month;
    temp.day = day;

    temp.difference = calcJulianDate(temp);
    tempOne.difference = calcJulianDate(tempOne);

    if (temp > tempOne)
    {
        temp.difference = (temp.difference - tempOne.difference);
    }
    else if (tempOne > temp)
    {
        temp.difference = (tempOne.difference - temp.difference);
    }

    return temp;
}

/* **********************************************************
            Date Date::operator >> () : Extraction operator
   ********************************************************** */

istream& operator >> (istream& strm, Date& obj)
{
    cout << "Enter a year: (1900 - 2020): ";
    strm >> obj.year;
    obj.setYear(obj.year);

    cout << "Enter a month (1 - 12): ";
    strm >> obj.month;
    obj.setMonth(obj.month);

    cout << "Enter a day: ";
    strm >> obj.day;
    obj.setDay(obj.day);

    return strm;
}

/* **********************************************************
            Date Date::operator << () : Insertion operator
   ********************************************************** */

ostream& operator << (ostream& strm, const Date& obj)
{
    return strm << obj.monthNames[obj.month] << " " << obj.day << ", " << obj.year;
}

/* **********************************************************
            Date::printFormatOne()
    This function outputs the date as 12/12/2012.
    ********************************************************** */

void Date::printFormatOne()
{
    cout << "\nSlash Style:\n";
    cout << month << "/" << day << "/" << year;
}

/* **********************************************************
            Date::printFormatTwo (void)
    This function outputs the date as DECEMBER 12, 2012
    ********************************************************** */

void Date::printFormatTwo()
{
    std::cout << "\n\nU.S. Style:\n";
    std::cout << monthNames[month] << " " << day << ", " << year;
}

/* **********************************************************
            Date::printFormatThree (void)
    This function outputs the date as 12 DECEMBER, 2012
    ********************************************************** */

void Date::printFormatThree()
{
    cout << "\n\nEuropean Style:\n";
    cout << day << " " << monthNames[month] << " " << year;
}