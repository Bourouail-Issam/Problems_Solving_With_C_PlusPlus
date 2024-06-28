
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
bool IsLeapYear(short Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}
short NumberDaysInMonth(short Year, short Month) {
    if (Month <= 0 || Month > 12)
        return 0;
    short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberDaysinMonth[Month - 1]);
}
bool IsLastDayInMonth(stMyDate Date) {

    return (Date.Day == NumberDaysInMonth(Date.Year, Date.Month));
}
bool IsLastMontInYear(short Month) {

    return (Month == 12);
}
stMyDate IncreaseDateByOneDay (stMyDate Date){

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
}
int main()
{
    stMyDate Date = ReadFullDate();
    Date = IncreaseDateByOneDay(Date);
    //cout << "\nDate After adding one day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n\n";
    printf("\nDate After adding one day is : %d/%d/%d\n\n", Date.Day, Date.Month, Date.Year);
}

