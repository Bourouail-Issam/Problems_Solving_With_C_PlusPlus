
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

strTime ReadTime() {
    strTime MyTime; 
     MyTime.Days = ReadPositiveNumber("Please Enter Number Of Days : ");
     MyTime.Hours = ReadPositiveNumber("Please Enter Number Of Hours : ");
     MyTime.Minutes = ReadPositiveNumber("Please Enter Number Of Minutes: ");
     MyTime.Seconds = ReadPositiveNumber("Please Enter Number Of Seconds : ");
     return MyTime;
}

int TimeToSeconds(strTime MyTime) {
    int remainder = MyTime.Days * 24 * 60 * 60;
    remainder += MyTime.Hours * 60 * 60;
    remainder += MyTime.Minutes * 60;
    remainder += MyTime.Seconds;
    return remainder;
}

int main()
{
    cout << endl <<TimeToSeconds(ReadTime()) << " Seconds \n";
    return 0;
}
