#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

enum enDateCompare { Before = -1, Equal = 0, After = 1 };
struct stMyDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
struct stPeriods {
    stMyDate StartDate;
    stMyDate EndDate;
};

//------------------------
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
stPeriods ReadPeriod() {
    stPeriods Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}
//------------------------
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

//------------------------
bool IsDate1BeforeDate2(stMyDate Date1, stMyDate Date2)
{
    return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stMyDate Date1, stMyDate Date2)
{
    return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false;
}
bool IsDate1AfterDate2(stMyDate Date1, stMyDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

//------------------------
short GetDifferenceInDays(stMyDate Date1, stMyDate Date2, bool IncludeEndDay = false)
{
    short Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;

}
int PeriodLengthInDays(stPeriods Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}


enDateCompare  CompareDates(stMyDate Date1, stMyDate Date2) 
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsOverlapPeriods (stPeriods Period1, stPeriods Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
        ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
        return true;
}
bool isDateInPeriod(stMyDate checkDate, stPeriods Period) 
{
    return !(CompareDates(checkDate, Period.StartDate) == enDateCompare::Before
        ||
        CompareDates(checkDate, Period.EndDate) == enDateCompare::After);
}

int countOverlapDays(stPeriods Period1, stPeriods Period2) {

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    int OverlapDays = 0;
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate,Period1.EndDate))
        {
            if (isDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else {
        while (IsDate1AfterDate2(Period2.EndDate, Period2.StartDate))
        {
            if (isDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;

            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }
    return OverlapDays;
}



int main()
{
    //------------------------
    cout << "\nEnter Period 1 :\n";
    stPeriods Period1 = ReadPeriod();

    //------------------------
    cout << "\n=>Enter Period 2 :\n\n";
    stPeriods Period2 = ReadPeriod();

    //------------------------
    cout << "\n\nOverlap Days count Is : " 
        << countOverlapDays(Period1,Period2) << endl;

    system("pause>0");
    return 0;
}
    