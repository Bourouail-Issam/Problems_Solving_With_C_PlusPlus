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
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stMyDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool isWeekEnd(stMyDate Date)
{
    short DanIndex = DayOfWeekOrder(Date);
    return (5 == DanIndex || 6 == DanIndex);
}
bool isBusinessDay(stMyDate Date)
{
    return !isWeekEnd(Date);
}
short GetDifferenceInDays(stMyDate Date1, stMyDate Date2, bool IncludeEndDay = false) {
    short Days = 0;
    short SwapFlagValue = 1;


    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}
string DayShortName(short WeekDay)
{
    string NameDaysWeek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return NameDaysWeek[WeekDay];
}



short CalculateVacationDays (stMyDate DateFrom, stMyDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom,DateTo))
    {
        if (isBusinessDay(DateFrom))
            DaysCount++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
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

int main()
{
    //------------------------
    cout << "Vacation Starts : \n";
    stMyDate Date1 = ReadFullDate();

    //------------------------
    cout << "\n\nVacation Ends : \n";
    stMyDate Date2 = ReadFullDate();
    
    //------------------------
    cout << "\n\nVacation From : " << DayShortName(DayOfWeekOrder(Date1)) << " , ";
    printf("%d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

    //------------------------
    cout << "Vacation To : " << DayShortName(DayOfWeekOrder(Date2)) << " , ";
    printf("%d/%d/%d\n\n", Date2.Day, Date2.Month, Date2.Year);

    //------------------------
    cout << "Actucal Vacation Days is : " << CalculateVacationDays(Date1,Date2) << endl;

    return 0;
}
