
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
bool IsLeapYear (short Year){
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}
short NumberDaysInMonth(short Year , short Month) {
    if (Month <= 0 || Month >12)
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
int main() {
    stMyDate Date = ReadFullDate();

    if (IsLastDayInMonth(Date))
        cout << "\nYes , Day is last in Month\n";
    else
        cout << "\nNo, Day is Not last in Month\n";

    if (IsLastMontInYear(Date.Month))
        cout << "Yes , Month is last in year\n";
    else
        cout << "No, Month is Not last in Year\n";

    system("pause>0");
    return 0;
};

