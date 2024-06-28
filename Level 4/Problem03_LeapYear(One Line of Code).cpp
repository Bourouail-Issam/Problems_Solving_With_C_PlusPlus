

#include <iostream>
using namespace std;

int ReadNumber()
{
    int number;
    cout << "Please enter Year : ";
    cin >> number;
    return number;
}
bool checkLeapYear(int year)
{
    return  ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}
int main()
{
    int Year = ReadNumber();
    if (checkLeapYear(Year))
        cout << "\nYes, Year " << Year << " it's Leap Year\n";
    else
        cout << "\nNo, Year " << Year << " it's not Leap Year\n";


}


