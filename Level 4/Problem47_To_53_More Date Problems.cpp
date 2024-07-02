#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stMyDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
bool IsLeapYear(short Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}
short NumberDaysInMonth(short Year, short Month) {
    if (Month <= 0 || Month > 12)
        return 0;
    short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberDaysinMonth[Month - 1]);
}
bool IsLastDayInMonth(stMyDate Date)
{
    return (Date.Day == NumberDaysInMonth(Date.Year, Date.Month));
}
stMyDate IncreaseDateByOneDay(stMyDate Date) {

    if (IsLastDayInMonth(Date))
    {
        if (12 == Date.Month) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return  Date;
}
bool IsDate1BeforeDate2(stMyDate Date1, stMyDate Date2)
{
    return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short GetDifferenceInDays(stMyDate Date1, stMyDate Date2, bool IncludeEndDay = false) {

    short Days = 0;
    
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days  : Days ;
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;    

    a = (14 - Month) / 12;
    y = Year - a;     
    m = Month + (12 * a) - 2; 
    
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
}


string DayShortName(short WeekDay)
{
    string NameDaysWeek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDaysWeek[WeekDay];
}
short DayOfWeekOrder(stMyDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
bool isEndOfWeek(stMyDate Date) {
    return DayOfWeekOrder(Date) == 6;
}
bool isWeekWeek(stMyDate Date)
{
    short DanIndex = DayOfWeekOrder(Date);
    return ( 5 == DanIndex || 6 == DanIndex );
}
bool isBusinessDay(stMyDate Date) {
    return !isWeekWeek(Date);
}
short DaysUnitilTheEndOfWeek(stMyDate Date) 
{
    return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(stMyDate Date)
{
    stMyDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberDaysInMonth(Date.Year, Date.Month);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stMyDate Date) {

    stMyDate EndOfMonthDate;
    EndOfMonthDate.Day = 31;
    EndOfMonthDate.Month = 12;
    EndOfMonthDate.Year = Date.Year ;
    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}
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
stMyDate ReadFullDate() {
    stMyDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
stMyDate GetSystemDate() {
    stMyDate Date;

    time_t MyTime = time(0); // Get time now
    tm* now = localtime(&MyTime);

    Date.Year = (now->tm_year + 1900);
    Date.Month = (now->tm_mon + 1);
    Date.Day = now->tm_mday;

    return Date;
}
int main()
{
    stMyDate DateNow = GetSystemDate();
    cout << "Today is " << DayShortName(DayOfWeekOrder(DateNow)) << " , ";
    printf("%d/%d/%d\n\n", DateNow.Day, DateNow.Month, DateNow.Year);
    
    //----------------------------
    cout << "Is is End of Week?\n";
    if (isEndOfWeek(DateNow))
        cout << "Yes it is an End of Week.\n\n";
    else
        cout << "No Not end of an Week\n\n";
    //----------------------------
    cout << "Is is WeekEnd?\n";
    if (isWeekWeek(DateNow))
        cout << "Yes it is a Week end.\n\n";
    else
        cout << "No it is " << DayShortName(DayOfWeekOrder(DateNow)) << " Not a Week end\n\n";
    //----------------------------
    cout << "Is is Business Day?\n";
    if (isBusinessDay(DateNow))
        cout << "Yes it is a business day.\n\n";
    else
        cout << "No it is Not a business day\n\n";
    //----------------------------
    printf("Days until end of week : %d Days(s).\n",
        DaysUnitilTheEndOfWeek(DateNow));
    //----------------------------
    printf("Days until end of Month : %d Days(s).\n",
        DaysUntilTheEndOfMonth(DateNow));
    //----------------------------
    printf("Days until end of week : %d Days(s).\n",
        DaysUntilTheEndOfYear(DateNow));
    return 0;
}
