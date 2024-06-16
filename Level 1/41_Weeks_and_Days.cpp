
#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string Msg) {
    float Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float HoursTo_Weeks(int NumbersOfHours) {
    return (float) NumbersOfHours / 24 / 7;
}
float HoursTo_Days(int NumbersOfHours) {
    return (float)NumbersOfHours / 24 ;
}
void PrintPrimeOrNot(float NumberOf_Hours , float NumberOf_Weeks, float NumberOf_Days) {

    cout << NumberOf_Hours << " Hours \n";
    cout << NumberOf_Weeks << " Weeks \n";
    cout << NumberOf_Days << " Days \n";
}
int main()
{
    float NumbersOfHours = ReadNumber("Please Enter Number Of Hours : ");
    float NumberOf_Weeks = HoursTo_Weeks(NumbersOfHours);
    float NumberOf_Days = HoursTo_Days(NumbersOfHours);

    PrintPrimeOrNot(NumbersOfHours, NumberOf_Weeks, NumberOf_Days);

}
