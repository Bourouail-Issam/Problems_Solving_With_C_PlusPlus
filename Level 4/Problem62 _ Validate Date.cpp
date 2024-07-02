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

bool IsValidateDay(stMyDate Date) {

    if (Date.Month < 1 || Date.Month >12)
        return false;

    if (Date.Year < 1)
        return false;

    if (1 > Date.Day || NumberDaysInMonth(Date.Year, Date.Month) < Date.Day)
        return false;

    return true;
}

bool IsValidateDateSolution2(stMyDate Date) 
{
    if (1 > Date.Day || 31 < Date.Day)
        return false;

    if (1 > Date.Month || 12 < Date.Month)
        return false;

    if (Date.Month == 2) 
    {
        if (IsLeapYear(Date.Year))
        {
            if (29 < Date.Day)
                return false;
        }
        else
        {
            if (28 < Date.Day)
                return false;
        }
    }

    if (NumberDaysInMonth(Date.Year, Date.Month) < Date.Day)
        return false;

    return true;
}
int main()
{
    stMyDate date = ReadFullDate();

    if (IsValidateDay(date))
        cout << "\n\nYes, Date is valide date.\n\n";
    else
        cout << "\n\nNo, Date is a NOT valide date.\n\n";

    system("pause>0");
    return 0;
}
