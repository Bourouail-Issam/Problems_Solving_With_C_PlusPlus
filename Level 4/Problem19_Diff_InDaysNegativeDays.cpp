#pragma warning(disable : 4996)
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
stMyDate ReadFullDate() {
    stMyDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
stMyDate GetSystemDate() {
    stMyDate Date;

    time_t MyTime = time(0);
    tm* now = localtime(&MyTime);

    Date.Year = (now->tm_year + 1900);
    Date.Month = (now->tm_mon + 1);
    Date.Day = now->tm_mday;

    return Date;
}
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
bool IsLastMontInYear(short Month)
{
    return (Month == 12);
}

stMyDate IncreaseDateByOneDay(stMyDate Date) {

    if (IsLastDayInMonth(Date))
    {
        if (IsLastMontInYear(Date.Month)) {
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
void SwapDate(stMyDate& Date1, stMyDate& Date2) {
    stMyDate TempDate;
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;

    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;
}
short GetDifferenceInDays(stMyDate Date1, stMyDate Date2, bool IncludeEndDay = false) {
    short Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2)) {
        SwapDate(Date1, Date2);
        SwapFlagValue = -1;
    }
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}
int main()
{
    stMyDate Date1 = ReadFullDate();
    stMyDate Date2 = ReadFullDate();

    cout << "\NDiffrence is " << GetDifferenceInDays(Date1, Date2) << " Day(s)\n";
    cout << "\NDiffrence (Including End Day) is " << GetDifferenceInDays(Date1, Date2, true) << " Day(s)\n";
}

