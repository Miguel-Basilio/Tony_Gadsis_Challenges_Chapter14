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

          //  Date::setYear() : int

void Date::setYear(int yyyy)
{
    yyyy >= 1900 && yyyy <= 2022 ? year = yyyy : year = 1900;
}


           // Date::setMonth() : int


void Date::setMonth(int mm)
{
    mm >= JANUARY && mm <= DECEMBER ? month = mm : month = 1;
}

        //    Date::setDay() : int


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


          //  Date::isLeapYear()


bool Date::isLeapYear() const
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    return false;
}

          //  Date::helpIncrement(): This helper function determines whether the day, day and
           //month, or day month and year values should be incremented.


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

            //Date &Date::operator++() : Prefix ++
  

Date& Date::operator++()
{
    ++day;
    helpIncrement();
    return *this;
}


           // Date Date::operator++(int) : Postfix ++
 

Date Date::operator++(int)
{
    Date tempDate(year, month, day);

    day++;
    helpIncrement();

    return tempDate;
}


          //  Date::helpDecrement(): This helper function determines whether year or month should be decremented. 

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

//      Date Date::operator--() : Prefix --


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


           // Date Date::operator--(int) : Postfix --


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


         //   Date::calcJulianDate() : calculates the Julian dates for two date  objects.

int Date::calcJulianDate(const Date& dateOne)
{
    int julianDate = (1461 * (dateOne.year + 4800 + (dateOne.month - 14) / 12)) / 4 +
        (367 * (dateOne.month - 2 - 12 * ((dateOne.month - 14) / 12))) / 12 -
        (3 * ((dateOne.year + 4900 + (dateOne.month - 14) / 12) / 100)) / 4 +
        (dateOne.day - 32075);

    return julianDate;
}


           // bool Date::operator >() : Greater


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

          //  Date Date::operator -() : Binary -
  

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


           // Date Date::operator >> () : Extraction operator


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

           // Date Date::operator << () : Insertion operator
  
ostream& operator << (ostream& strm, const Date& obj)
{
    return strm << obj.monthNames[obj.month] << " " << obj.day << ", " << obj.year;
}



void Date::printFormatOne()
{
    cout << "\nSlash Style:\n";
    cout << month << "/" << day << "/" << year;
}



void Date::printFormatTwo()
{
    std::cout << "\n\nU.S. Style:\n";
    std::cout << monthNames[month] << " " << day << ", " << year;
}



void Date::printFormatThree()
{
    cout << "\n\nEuropean Style:\n";
    cout << day << " " << monthNames[month] << " " << year;
}