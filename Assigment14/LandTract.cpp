#include "LandTract.h"

  //  Calculates the area of two tracts of land.
void LandTract::calcArea()
{
    int w = width.getFeet() * 12 + width.getInches();
    int len = length.getFeet() * 12 + length.getInches();

    area = (w * len);
}

// Returns true if the current object is set to a value equal to that of right.
bool LandTract::operator == (const LandTract& right)
{
    bool status;

    if (area == right.area)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}