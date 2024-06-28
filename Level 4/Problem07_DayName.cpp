#include <iostream>

using namespace std;

int Read_Year_Month_Day(string msg) {
    int number;
    cout << "Please Enter a " << msg << " ? ";
    cin >> number;
    cout << endl;
    return number;
 }

short CalcDayOrder(short year, short month, short day)
{
     short a, y, m;
     a = (14 - month) / 12;
     y = year - a;
     m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
 string NameDay(short orderDay)
 {
     string NameDays[] = 
     { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
     return NameDays[orderDay];
 }
int main()
{
    short year, month, day, orderDay;
    year = Read_Year_Month_Day("year");
    month = Read_Year_Month_Day("Month");
    day = Read_Year_Month_Day("Day");
    orderDay = CalcDayOrder(year, month, day);
    cout << "Date      : " << day << "/" << month << "/" << year;
    cout << "\nDay Order : " << orderDay;
    cout << "\nDay Name  : " << NameDay(orderDay) << endl;

}
 
