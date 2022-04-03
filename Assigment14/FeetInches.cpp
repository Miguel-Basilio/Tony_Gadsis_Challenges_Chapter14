#include "FeetInches.h"
#include <cstdlib>

#include <iostream>
using std::cin;
using std::cout;


           // FeetInches::simplify()
   // This function checks for values in the inches member
   // greater than twelve or less than zero. 
void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}


         //   Overloaded binary + operator
FeetInches FeetInches::operator + (const FeetInches& right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();

    return temp;
}


           // Overloaded binary - operator
FeetInches FeetInches::operator - (const FeetInches& right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();

    return temp;
}

//        Overloaded prefix ++ operator
FeetInches FeetInches::operator++()
{
    ++inches;
    simplify();

    return *this;
}

//    Overloaded postfix ++ operator
FeetInches FeetInches::operator++(int)
{
    FeetInches temp(feet, inches);

    inches++;
    simplify();

    return temp;
}
//   Overloaded > operator
bool FeetInches::operator > (const FeetInches& right)
{
    bool status;

    if (feet > right.feet)
    {
        status = true;
    }
    else if (feet == right.feet && inches > right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//        Overloaded < operator
bool FeetInches::operator < (const FeetInches& right)
{
    bool status;

    if (feet < right.feet)
    {
        status = true;
    }
    else if (feet == right.feet && inches < right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//       Overloaded == operator
bool FeetInches::operator == (const FeetInches& right)
{
    bool status;

    if (feet == right.feet && inches == right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//         Overloaded Greater Equal => operator
bool FeetInches::operator >= (const FeetInches& right)
{
    bool status;

    if (feet >= right.feet)
    {
        return true;
    }
    else if (feet == right.feet && inches >= right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//         Overloaded Less Equal <= operator
bool FeetInches::operator <= (const FeetInches& right)
{
    bool status;

    if (feet <= right.feet)
    {
        status = true;
    }
    else if (feet == right.feet && inches <= right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//     Overloaded Inequal != operator
bool FeetInches::operator != (const FeetInches& right)
{
    bool status;

    if (feet != right.feet)
    {
        status = true;
    }
    else if (feet == right.feet && inches != right.inches)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//   FeetInches::FeetInches multiply() : const obj &
FeetInches FeetInches::multiply(const FeetInches& right)
{
    FeetInches temp;

    temp.inches = ((feet * 12 + inches) * (right.feet * 12 + right.inches));
    temp.inches /= 12;
    temp.simplify();

    return temp;
}

//        Overloaded << operator
ostream& operator << (ostream& strm, const FeetInches& obj)
{
    strm << obj.feet << " feet, " << obj.inches << " inches";

    return strm;
}

//         Overloaded >> operator
istream& operator >> (istream& strm, FeetInches& obj)
{
    // Prompt the user for the feet
    cout << "Feet: ";
    strm >> obj.feet;

    // Prompt the user for the inches
    cout << "Inches: ";
    strm >> obj.inches;

    // Normalize the values
    obj.simplify();

    return strm;
}
