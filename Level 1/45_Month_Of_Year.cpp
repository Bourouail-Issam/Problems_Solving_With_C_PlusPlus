
#include <iostream>
#include <cmath>
using namespace std;

enum enNameMonthsOfYear {
    January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7,
    August = 8 , September = 9 , October = 10 , November = 11 , December = 12
};
int ReadIntervalNumber(string Msg, int From, int To) {
    int Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}
enNameMonthsOfYear ReadDayOfWeek() {
    return (enNameMonthsOfYear)ReadIntervalNumber("Please Enter Number of Months Between 1-12 : ", 1, 12);
}
string checkDays(enNameMonthsOfYear NumberMonth) {
    switch (NumberMonth)
    {
    case enNameMonthsOfYear::January:
        return "January";
    case enNameMonthsOfYear::February:
        return "February";
    case enNameMonthsOfYear::March:
        return "March";
    case enNameMonthsOfYear::April:
        return "April";
    case enNameMonthsOfYear::May:
        return "May";
    case enNameMonthsOfYear::June:
        return "June";
    case enNameMonthsOfYear::July:
        return "July";
    case enNameMonthsOfYear::August:
        return "August";
    case enNameMonthsOfYear::September:
        return "September";
    case enNameMonthsOfYear::October:
        return "October";
    case enNameMonthsOfYear::November:
        return "November";
    case enNameMonthsOfYear::December:
        return "December";
    }
}
int main()
{
    cout << "\nIt's " << checkDays(ReadDayOfWeek()) << endl;
    return 0;
}
