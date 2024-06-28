
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

bool IsDate1BeforeDate2(stMyDate Date1, stMyDate Date2) { 

    return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
int main()
{
    stMyDate Date1 = ReadFullDate();
    stMyDate Date2 = ReadFullDate();
    
    if (IsDate1BeforeDate2(Date1, Date2)) 
        cout << "\nYes, Date1 is Less than Date2 \n";
    else
        cout << "\nNo, Date1 is Not Less than Date2 \n";

    system("pause>0");
    return 0;
   
};

