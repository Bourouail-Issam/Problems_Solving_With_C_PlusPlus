
#include <iostream>
using namespace std;

short Read_Yaer_Month_Day(string Msg) {
    short number;
    cout << "\nPlease enter a " << Msg << " ? ";
    cin >> number;
    return number;
}
bool isLeapYear(short year) {
    return(0 == year % 400 || (0 == year % 4 && 0 != year % 100));
}
short numberDaysInYear(short year) {
    return(isLeapYear(year) ? 366 : 365);
}

short NumberOfDaysInAMonth(short year, short month) {
    if (0 == month)
        return 0;
    short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (2 == month ? (isLeapYear(year) ? 29 : 28) : NumberDaysinMonth[month - 1]);
}

short NumberOfDaysFromTheBeginnningYear(short Year, short Month, short Day) 
{
    short TotalDays = 0;
    for (short i = 1; i <= Month-1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(Year, i);
    }
    TotalDays += Day;
    return TotalDays;
}
int main() {
    short Year, Month, Day;
    Day = Read_Yaer_Month_Day("Day");
    Month = Read_Yaer_Month_Day("Month");
    Year = Read_Yaer_Month_Day("Year");

    cout << "\nNumber Of Days from the beginning of the year is " 
         << NumberOfDaysFromTheBeginnningYear(Year,Month, Day) << endl << endl;
};

