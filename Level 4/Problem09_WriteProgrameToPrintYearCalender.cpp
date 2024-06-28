
#include <iostream>
using namespace std;

short ReadYear()
{
    short year;
    cout << "Please enter a year ? ";
    cin >> year;
    return year;
}
bool isLeapYear(short year)
{
    return(0 == year % 400 || (0 == year % 4 && 0 != year % 100));
}
short DayOfWeekOrder(short year, short month, short day)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string MonthShortName(short month) {
    string months [12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    return (months[month - 1]);
}
short NumberOfDaysInAMonth(short month, short year){
    if (1 > month || month > 12)
        return 0;
    short NumberDaysinMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (2 == month ? (isLeapYear(year) ? 29 : 28) : NumberDaysinMonth[month - 1]);
}

void PrintMonthCalendar(short Month, short Year) {

    int NumberOfDays;
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInAMonth(Month, Year);
  
    printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++)
        printf("     ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n  _________________________________\n");
}
void PrintYearCalendar(short year) {
    cout << "\n\n-------------------------------------\n\n";
    cout << "\tCalendar - " << year;
    cout << "\n\n-------------------------------------\n\n";

    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, year);
    }

}
int main()
{
    PrintYearCalendar(ReadYear());
}

