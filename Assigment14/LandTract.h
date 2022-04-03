#pragma once
#include "FeetInches.h"

class LandTract
{
private:
    int area;

    FeetInches width;
    FeetInches length;

public:
    LandTract(FeetInches w, FeetInches l) : width(w), length(l)
    {
        area = 0;
        calcArea();
    }

    void calcArea();

    int getArea() const
    {
        return area;
    }

    // Overloaded operator
    bool operator == (const LandTract&);                    // Overloaded ==
};