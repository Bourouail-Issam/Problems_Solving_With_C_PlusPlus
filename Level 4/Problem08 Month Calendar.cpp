#include <iostream>
#include <cstdio>

using namespace std;

int Read_Year_Month_Day(string msg) {
    int number;
    cout << "Please Enter a " << msg << " ? ";
    cin >> number;
    cout << endl;
    return number;
}

bool checkIsLeapYear(int Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}

short NumberDaysInMonth(int Year, int Month)
{
    if (Month < 1 || Month > 12)
        return 0;

    short ArrDays[12] = { 31,28, 31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2 ? (checkIsLeapYear(Year) ? 29 : 28) : ArrDays[Month - 1]);
}
short DayOfWeekOrder(short year, short month, short day)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string MonthShortName(short month)
{
    string Months[12] ={ "January","February","March","April","May","June","July",
                         "August","September","October","November","December"};
    return Months[month-1];
}
void PrintMonthClander(short year, short month)
{
    //index of the day from 0 to 6
    short current = DayOfWeekOrder(year, month, 1);
    
    //number Day In Month 28 or 29 or 30 or 31
    short numberOfDaysInMonth = NumberDaysInMonth(year, month);
   
    string NameMonth = MonthShortName(month);

    printf("\n---------------%s---------------\n\n",NameMonth.c_str() );
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n\n";

    for (short i = 0; i < current; i++)
        cout << "     ";
    
    int counter = current;
    for (short i = 1; i <= numberOfDaysInMonth; i++)
    {
        counter++;
        printf("%5d", i);
        if (counter >= 7) {
            counter = 0;
            cout << endl<<endl;
        }
        
    }
    cout << "\n\n------------------------------------";
}

int main()
{
    short year, month;
    year = Read_Year_Month_Day("year");
    month = Read_Year_Month_Day("Month");

    PrintMonthClander(year,month);

}

