
#include <iostream>
using namespace std;

struct stMyDate {
    int Day = 0;
    int Month = 0;
    int Year = 0;
};
short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year : ";
    cin >> Year;
    return Year;
}
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month : ";
    cin >> Month;
    return Month;
}
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day : ";
    cin >> Day;
    return Day;
}
short ReadDaysToAdd() {
    short Year;
    cout << "\nHow Many Days to Add : ";
    cin >> Year;
    cout << endl;
    return Year;
}
stMyDate ReadFullDate() {
    stMyDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}
bool isLeapYear(short year) {
    return(0 == year % 400 || (0 == year % 4 && 0 != year % 100));
}
short numberDaysInYear(short year) {
    return(isLeapYear(year) ? 366 : 365);
}
short NumberDaysInMonth(short year, short month) {
    if (0 == month)
        return 0;
    short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (2 == month ? (isLeapYear(year) ? 29 : 28) : NumberDaysinMonth[month - 1]);
}


short NumberOfDaysFromTheBeginnningYear(short Year, short Month, short Day) 
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
        TotalDays += NumberDaysInMonth(Year, i);

    TotalDays += Day;

    return TotalDays;
}

stMyDate DateAddDays(stMyDate Date, short Days) {

    short MonthDays = 0;
    short RemainingDays = Days + NumberOfDaysFromTheBeginnningYear(Date.Year, Date.Month, Date.Day);

    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberDaysInMonth(Date.Year, Date.Month);

        if (MonthDays < RemainingDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Year++;
                Date.Month = 1;
            }
            
        }
        else {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main() 
{
    stMyDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Date, Days);
    cout << "\nDate after adding [" << Days << "] days is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    system("pause>0");
    return 0;
};

