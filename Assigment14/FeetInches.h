#pragma once
#include <iostream>
using std::istream;
using std::ostream;

class FeetInches
{
private:
    int feet;                        // To hold a number of feet
    int inches;                        // To hold a number of inches

    void simplify();                // Defined in FeetInches.cpp

public:

    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Copy Constructor challenge 11
    FeetInches(const FeetInches& obj)
    {
        feet = obj.feet;
        inches = obj.inches;
    }
    // Mutator functions
    void setFeet(int f)
    {
        feet = f;
    }

    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    FeetInches multiply(const FeetInches&); //challenge 11

    // Accessor functions
    int getFeet() const
    {
        return feet;
    }

    int getInches() const
    {
        return inches;
    }

    // Overload operator functions
    FeetInches operator + (const FeetInches&);            // Overloaded +
    FeetInches operator - (const FeetInches&);            // Overloaded -
    FeetInches operator ++ ();                                    // Prefix ++
    FeetInches operator ++ (int);                                // Postfix ++

    bool operator > (const FeetInches&);                    // Overloaded >
    bool operator < (const FeetInches&);                    // Overloaded <
    bool operator == (const FeetInches&);                    // Overloaded ==
    bool operator >= (const FeetInches&);                    // Greater Equal
    bool operator <= (const FeetInches&);                    // Lesser Equal
    bool operator != (const FeetInches&);                    // Inequal

    // Friends
    friend ostream& operator << (ostream&, const FeetInches&);
    friend istream& operator >> (istream&, FeetInches&);
};
