
#include <iostream>
#include <cmath>
using namespace std;

enum enNameDaysOfWeek
{
    Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7
};
int ReadIntervalNumber(string Msg , int From , int To) {
    int Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}
enNameDaysOfWeek ReadDayOfWeek() {
    return (enNameDaysOfWeek) ReadIntervalNumber("Please Enter Number of day Between 1-7 : ", 1, 7);
}
string checkDays (enNameDaysOfWeek NumberDay) {
    switch (NumberDay)
    {
    case enNameDaysOfWeek::Sunday:
        return "Friday";
    case enNameDaysOfWeek::Monday:
        return "Monday";
    case enNameDaysOfWeek::Tuesday:
        return "Tuesday";
    case enNameDaysOfWeek::Wednesday:
        return "Wednesday";
    case enNameDaysOfWeek::Thursday:
        return "Thursday";
    case enNameDaysOfWeek::Friday:
        return "Friday";
    case enNameDaysOfWeek::Saturday:
        return "Saturday";
    }
}

int main()
{

    cout << "\nIt's " << checkDays(ReadDayOfWeek()) << endl;
    return 0;
}
