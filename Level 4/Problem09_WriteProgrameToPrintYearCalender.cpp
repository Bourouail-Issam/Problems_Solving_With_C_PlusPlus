
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
void PrintMonthClander(short month, short year)
{
    int NumberOfDays;

    //index of the day from 0 to 6
    short current = DayOfWeekOrder(year, month, 1);

    //number Day In Month 28 or 29 or 30 or 31
    NumberOfDays = NumberOfDaysInAMonth(month, year);

    printf("\n------------------- %s -------------------\n\n",
        MonthShortName(month).c_str());

    cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat  \n\n";

    int i;
    for (i = 0; i < current; i++)
        cout << "      ";


    for (short j = 1; j <= NumberOfDays; j++)
    {

        printf("%6d", j);

        if (++i == 7) {
            i = 0;
            cout << endl << endl;
        }

    }
    cout << "\n\n--------------------------------------------\n\n";
}


void PrintYearCalendar(short year) {
    cout << "\n\n-------------------------------------\n\n";
    cout << "\tCalendar - " << year;
    cout << "\n\n-------------------------------------\n\n";

    for (short i = 1; i <= 12; i++)
    {
        PrintMonthClander(i, year);
    }

}
int main()
{
    PrintYearCalendar(ReadYear());
}

