#include <iostream>
#include <iomanip>
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
int NumberOfDaysInYear(int Year) {
    return (checkLeapYear(Year) ? 366 : 365);
}
int NumberOfHoursInYear(int Year) {
    return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutesInYear(int Year) {
    return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(int Year) {
    return NumberOfMinutesInYear(Year) * 60;
}
int main()
{
    int Year = ReadNumber();
    cout << "\n\nNumber of Days in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
    cout << "\nNumber of Hours in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year);
    cout << endl;
    
}



