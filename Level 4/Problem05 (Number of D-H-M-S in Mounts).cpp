
#include <iostream>
using namespace std;

int ReadYear() {
    int Year;
    cout << "Please enter a year to check ?";
    cin >> Year;
    return Year;
}
int ReadMounth() {
    int Month;
    cout << "Please enter a Month to check ?";
    cin >> Month;
    return Month;
}
bool checkIsLeapYear(int Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}
short CheckMonth (int NumberMonth , bool isLeapYear) {
    switch (NumberMonth) {
    case 1:
        return 31;
    case 2:
        return (isLeapYear ? 29 : 28);
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}
int NumberDaysInMonth(int Year, int Month){

    //Optimise Code
    // return (CheckMonth(Month, checkIsLeapYear(Year)));

    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
        return (checkIsLeapYear(Year) ? 29 : 28);

    short ArrDays31[7] = { 1,3,5,7,8,10,12 };
    for ( short i = 0; i < 7; i++)
    {
        if (Month == ArrDays31[i])
            return 31;
    }
    return 30;
}
int NumberHoursInMonth(int Year, int Month){
    return (NumberDaysInMonth(Year , Month) * 24);
}
int NumberMinutesInMonth(int Year, int Month) {
    return (NumberHoursInMonth(Year, Month) * 60);
}
int NumberSecondsInMonth(int Year, int Month) {
    return (NumberMinutesInMonth(Year, Month) * 60);
}
int main(){
    int Year = ReadYear();
    int Month = ReadYear();
    cout << "\nNumber of Day     in Month [" << Month << "] is " << NumberDaysInMonth(Year, Month) << endl;
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberHoursInMonth(Year, Month) << endl;
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberMinutesInMonth(Year, Month) << endl;
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberSecondsInMonth(Year, Month) << endl;
}
