#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;

struct stMyDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};
struct stPeriods{
    stMyDate StartDate;
    stMyDate EndDate;
};
bool IsDate1BeforeDate2(stMyDate Date1, stMyDate Date2)
{
    return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsDate1EqualDate2(stMyDate Date1, stMyDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false);
}
enum enCompareDate { Before = -1, Equale = 0, After = 1 };

enCompareDate CompareDate1AndDate2(stMyDate Date1, stMyDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enCompareDate::Equale;

    return enCompareDate::After;
}

bool IsOverLapPeriods(stPeriods Period1, stPeriods Period2) 
{
    if (CompareDate1AndDate2(Period2.EndDate, Period1.StartDate) == enCompareDate::Before
        || CompareDate1AndDate2(Period2.StartDate, Period1.EndDate) == enCompareDate::After
        )
        return false;
    
    return true;
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
    stPeriods Period1, Period2;
    //------------------------
    cout << "=>Enter Period 1 : \nEnter Start Date :\n\n";
    Period1.StartDate = ReadFullDate();

    //------------------------
    cout << "\nEnter End Date :\n\n";
    Period1.EndDate = ReadFullDate();

    //------------------------;
    cout << "\n\n=>Enter Period 2 : \nEnter Start Date :\n\n";
    Period2.StartDate = ReadFullDate();

    //------------------------
    cout << "\nEnter End Date :\n\n";
    Period2.EndDate = ReadFullDate();

    if (IsOverLapPeriods(Period1, Period2))
        cout << "Yes, Period Overlap";
    else
        cout << "\nNo, Period is Not Overlap";


    system("pause>0");
    return 0;
}
