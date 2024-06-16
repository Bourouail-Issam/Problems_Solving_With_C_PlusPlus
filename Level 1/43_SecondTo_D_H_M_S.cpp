
#include <iostream>
#include <cmath>
using namespace std;

struct strTime { int Days, Hours, Minutes, Seconds; };

int ReadPositiveNumber(string Msg) {
    int Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

strTime SecondsToDate(int NumbersOfSeconds) {

    const int secondsPerDays = 24 * 60 * 60;
    const int secondsPerHours = 60 * 60;
    const int secondsPerMinutes = 60;
    strTime MyTime;

    MyTime.Days = floor(NumbersOfSeconds / secondsPerDays);
    int remainder = (NumbersOfSeconds % secondsPerDays);

    MyTime.Hours = floor(remainder / secondsPerHours);
    remainder = (remainder % secondsPerHours);

    MyTime.Minutes = floor(remainder / secondsPerMinutes);
    remainder = (remainder % secondsPerMinutes);

    MyTime.Seconds = remainder;
    return MyTime;
}
void PrintTime(strTime MyTime) {
    cout << endl << MyTime.Days << ":" << MyTime.Hours << ":" 
         << MyTime.Minutes << ":" << MyTime.Seconds<< endl;
}
int main()
{
    int NumbersOfSeconds = ReadPositiveNumber("Please Enter Number Of Seconds : ");
    PrintTime(SecondsToDate(NumbersOfSeconds));
    return 0;
}
