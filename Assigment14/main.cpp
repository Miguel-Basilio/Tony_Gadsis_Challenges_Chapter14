#include <iostream>
#include "input.h"
#include "DayOfYear.h"
#include "Month.h"
#include "Date.h"
using namespace std;

int menuOption();
void Challenge3();
void Challenge7();
void Challenge8();


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
//        case 9: Challenge9(); break;
//        case 11: Challenge11(); break;
//        case 12: Challenge12(); break; // Extra credit 10 points
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
    cout << "MODIFIED DATE CLASS DEMO\n\n"
        << "This program demonstrates various abilities of the modified\n";

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

    cout << "Thank you for trying the Date class demo. Have a nice day!";

    cin.ignore();
    cin.get();

}