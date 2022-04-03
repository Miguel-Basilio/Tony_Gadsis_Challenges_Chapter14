#include <iostream>
#include "input.h"
#include "DayOfYear.h"
#include "Month.h"
#include "Date.h"
#include "FeetInches.h"
#include "LandTract.h"
#include <iomanip>

using namespace std;

int menuOption();
void Challenge3();
void Challenge7();
void Challenge8();
void Challenge9();
void Challenge11();
void Challenge12();

int main()

{
    do
    {
        system("cls");
        switch (menuOption())
        {
        case 0: exit(0); break;
        case 3: Challenge3(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break; // Extra credit 10 points
        case 9: Challenge9(); break;
        case 11: Challenge11(); break;
        case 12: Challenge12(); break; // Extra credit 10 points
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    cout << "\n\t\tChapter 14: Assignments Miguel Basilio (3/23/2022)";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t\t3. Challenge 3";
    cout << "\n\t\t7. Challenge 7";
    cout << "\nt\t\t8. Challenge 8";
    cout << "\nt\t\t9. Challenge 9";
    cout << "\nt\t\t11. Challenge 11";
    cout << "\nt\t\t12. Challenge 12";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t\t0. Exit";
    cout << "\n\t" << string(60, char(205)) << '\n';
    return (inputInteger("\t\tOption: ", 0, 12));
}

void Challenge3()
{
    system("cls");
    cout << "\n3. Day of the Year Modification\n" << string(100, char(196)) << "\n\n";

    int dayOfMonth = inputInteger("Enter a day of the month (1...31): ", 1, 31);
    int month = inputInteger("Enter a month (1...12): ");

    DayOfYear d1(dayOfMonth, month);
    d1.print();

    ++d1;
    cout << "\nDayOfYear ++d1:\n";
    d1.print();

    d1++;
    cout << "\nDayOfYear d1++:\n";
    d1.print();

    --d1;
    cout << "\nDayOfYear --d1\n";
    d1.print();

    d1--;
    cout << "\nDayOfYear d1--:\n";
    d1.print();

}

void Challenge7()
{
    system("cls");
    cout << "\n\tAssignment 7 - implementing and testing Month class\n";

    Month m1;           // testing the default constructor

    cin >>  m1;          // testing operator >>
    cout << "\n\tm1: " << m1 << '\n'; //testing operator <<

    string name = inputString("\n\tEnter the month name: ", false);
    Month m2(name);
    cout << "\tm2: " << m2 << '\n';
    
    ++m2;
    cout << "\t++m2: " << m2 << '\n';

    --m2;
    cout << "\t--m2: " << m2 << '\n';


    int number = inputInteger("\n\tEnter the month number (1...12): ", 1,12);
    Month m3(number);

    cout << "\tm3: " << m3 << '\n';

    m3++;
    cout << "\tm3++: " << m3 << '\n';

    m3--;
    cout << "\tm3--: " << m3 << '\n';

}

void Challenge8()
{
    cout << "MODIFIED DATE CLASS DEMO\n\n\n";

    cout << "Demonstrating the output of a date in three different styles:\n";
    Date date(2009, 6, 7);
    date.printFormatOne();
    date.printFormatTwo();
    date.printFormatThree();

    cout << "\n\nDemonstrating the overloaded Prefix ++ operator:\n";
    Date dateOne(2022, 12, 27);
    cout << "The date is:     " << dateOne << "\n";
    ++dateOne;
    cout << "The new date is: " << dateOne << "\n\n";

    cout << "Demonstrating the overloaded Postfix ++ operator:\n";
    Date dateTwo(2019, 11, 26);
    cout << "The date is:     " << dateTwo << "\n";
    dateTwo++;
    cout << "The new date is: " << dateTwo << "\n\n";

    cout << "Demonstrating the overloaded Prefix -- operator:\n";
    Date dateThree(2020, 12, 31);
    cout << "The date is:     " << dateThree << "\n";
    --dateThree;
    cout << "The new date is: " << dateThree << "\n\n";

    cout << "Demonstrating the overloaded Postfix -- operator:\n";
    Date dateFour(2000, 3, 1);
    cout << "The date is:     " << dateFour << "\n";
    dateFour--;
    cout << "The new date is: " << dateFour << "\n\n";

    cout << "Demonstrating the overloaded Extraction operator:\n\n";
    Date dateFive;
    cin >> dateFive;
    cout << "\nThis is the date you entered: " << dateFive << "\n\n";

    cout << "Demonstrating the overloaded Binary - operator:\n\n";
    cout << "The difference in days between \n"
        << dateFive << " and " << dateTwo << " is: ";
    dateFive = dateFive - dateTwo;
    cout << dateFive.getDifference() << " days.\n\n";
    cin.ignore();
    cin.get();

}

void Challenge9()
{
    FeetInches first, second;

    cout << "FEET INCHES MODIFICATION\n\n"
        << "This program asks you to enter two lenghts, measured in feet and inches.\n"
        << "It then tells you whether one distance is:\n\n"
        << "\tGreater than or equal to the other\n"
        << "\tLess than or equal to the other\n"
        << "\tNot the same as the other.\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter a distance in feet and inches.\n";
        cin >> first;

        cout << "Enter another distance in feet and inches.\n";
        cin >> second;

        cout << "\nThe values you entered are:\n";
        cout << first << " and " << second << "\n\n";

        if (first >= second)
        {
            cout << "True: First is greater than or equal to second.\n";
        }
        else
        {
            cout << "False: First is not greater than or equal to second.\n";
        }

        if (first <= second)
        {
            cout << "True: First is less than or equal to second.\n";
        }
        else
        {
            cout << "False: First is not less than or equal to second.\n";
        }

        if (first != second)
        {
            cout << "True: First does not equal second.\n";
        }
        else
        {
            cout << "False: First equals second.\n";
        }
        cout << "\n";
    }
    cin.get();
    cin.ignore();


}

void Challenge11()
{
    FeetInches first(15, 4);
    FeetInches second = first;
    FeetInches third, fourth;

    cout << "FEET INCHES - COPY CONSTRUCTOR & MULTIPLICATION DEMO\n\n"
        << "This program asks you to input two distances, measured in feet and inches.\n"
        << "It will multiply both values, and output the result in feet and inches.\n";
   
    cout << "Test:\n\n";
    cout << first << " multiplied by " << second << " equals:\n";
    cout << first.multiply(second) << " \n\n";

    cout << "Enter a distance in feet and inches:\n";
    cin >> third;

    cout << "\nEnter another distance in feet and inches.\n";
    cin >> fourth;
    cout << "\n" << third << " multiplied by " << fourth << " equals:\n";
    cout << (third.multiply(fourth));
    cout << "\n\nThank you for using this demo. Have a nice day!";
    cin.get();
    cin.ignore();
}

void Challenge12()
{
    const double TO_SQR_FT = 144.0;

    FeetInches w, l;

    cout << "Land Tract Area Calculator\n\n";
    cout << "This program lets you enter the dimensions for two tracts of land.\n"
        << "It will calculate the area for each, and output the result in square feet.\n"
        << "In addition it will tell you, whether the tracts are of same size.\n\n";

    cout << "Enter the width of tract #1:\n\n";
    cin >> w;
    cout << "\nEnter the length of tract #1:\n\n";
    cin >> l;

    LandTract lot(w, l);

    cout << "\nThe area of your lot is: ";
    cout << setprecision(2) << fixed;
    cout << (lot.getArea() / TO_SQR_FT) << " sq. ft.\n\n";

    cout << "Enter the width of tract #2:\n\n";
    cin >> w;
    cout << "\nEnter the length of tract #2:\n\n";
    cin >> l;

    LandTract garden(w, l);

    cout << "\nThe area of your garden is: ";
    cout << (garden.getArea() / TO_SQR_FT) << " sq. ft.\n\n";

    if (lot == garden)
    {
        cout << "Both tracts of land are of equal size.";
    }
    else
    {
        cout << "The tracts of land are of different size.";
    }

    cin.get();
    cin.ignore();
}