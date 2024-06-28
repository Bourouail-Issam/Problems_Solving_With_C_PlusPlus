
#include <iostream>
using namespace std;

int ReadYear() {
    int Year;
    cout << "Please enter a year to check ? ";
    cin >> Year;
    return Year;
}
int ReadMounth() {
    int Month;
    cout << "Please enter a Month to check ? ";
    cin >> Month;
    return Month;
}
bool checkIsLeapYear(int Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}

int NumberDaysInMonth(int Year, int Month) 
{
    if (Month < 1 || Month > 12)
        return 0;

    short ArrDays[12] = { 31,28, 31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2 ? (checkIsLeapYear(Year) ? 29 : 28) : ArrDays[Month - 1]);
}
int NumberHoursInMonth(int Year, int Month) {
    return (NumberDaysInMonth(Year, Month) * 24);
}
int NumberMinutesInMonth(int Year, int Month) {
    return (NumberHoursInMonth(Year, Month) * 60);
}
int NumberSecondsInMonth(int Year, int Month) {
    return (NumberMinutesInMonth(Year, Month) * 60);
}
int main() {
    int Year = ReadYear();
    int Month = ReadYear();
    cout << "\nNumber of Day     in Month [" << Month << "] is " << NumberDaysInMonth(Year, Month) << endl;
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberHoursInMonth(Year, Month) << endl;
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberMinutesInMonth(Year, Month) << endl;
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberSecondsInMonth(Year, Month) << endl;
}
