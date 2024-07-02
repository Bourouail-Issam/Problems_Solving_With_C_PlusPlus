#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stMyDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
struct stPeriods {
    stMyDate StartDate;
    stMyDate EndDate;
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
bool IsDate1EqualDate2(stMyDate Date1, stMyDate Date2)
{
    return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false ) : false;
}
bool IsDate1AfterDate2(stMyDate Date1, stMyDate Date2) 
{ 
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2)); 
}

short GetDifferenceInDays(stMyDate Date1, stMyDate Date2, bool IncludeEndDay = false) {

    short Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

enum enDateCompare {Before = -1, Equal = 0, After = 1 };

enDateCompare  CompareDates (stMyDate Date1, stMyDate Date2){
    if (IsDate1BeforeDate2(Date1,Date2))
        return enDateCompare::Before;
    
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool isDateInPeriod(stPeriods Period, stMyDate checkDate) {
    return !(CompareDates(checkDate, Period.StartDate ) == enDateCompare::Before
        ||
        CompareDates(checkDate, Period.EndDate) == enDateCompare::After);
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year : ";
    cin >> Year;
    return Year;
}
short ReadMonth() {
    short Month;
    cout << "Please enter a Month : ";
    cin >> Month;
    return Month;
}
short ReadDay() {
    short Day;
    cout << "Please enter a Day : ";
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
    stPeriods Period;
    //------------------------
    cout << "=>Enter Period 1 : \nEnter Start Date :\n\n";
    Period.StartDate = ReadFullDate();

    //------------------------
    cout << "\nEnter End Date :\n\n";
    Period.EndDate = ReadFullDate();

    //------------------------
    stMyDate checkDate;
    cout << "\nEnter Date to check :\n\n";
    checkDate = ReadFullDate();

    //------------------------
    if (isDateInPeriod(Period, checkDate))
        cout << "\n\nYes, Date is within period\n\n";
    else
        cout << "\n\nNo, Date is Not within period\n\n";

    system("pause>0");
    return 0;
}
