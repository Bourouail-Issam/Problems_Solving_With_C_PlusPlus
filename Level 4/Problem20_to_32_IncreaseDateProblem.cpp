#pragma warning(disable : 4996)
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
stMyDate GetSystemDate() {
    stMyDate Date;

    time_t MyTime = time(0);
    tm* now = localtime(&MyTime);

    Date.Year = (now->tm_year + 1900);
    Date.Month = (now->tm_mon + 1);
    Date.Day = now->tm_mday;

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
bool IsLastDayInMonth(stMyDate Date)
{
    return (Date.Day == NumberDaysInMonth(Date.Year, Date.Month));
}
bool IsLastMontInYear(short Month)
{
    return (Month == 12);
}

stMyDate IncreaseDateByOneDay(stMyDate Date) {

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
    return  Date;
}
stMyDate IncreaseDateByXDay(stMyDate Date , short Days) {

    for (short i = 0; i < Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stMyDate IncreaseDateByOneWeek(stMyDate Date) {

    for (int i = 0; i < 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stMyDate IncreaseDateByXWeek(stMyDate Date, short Weeks) {

    for (short i = 0; i < Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stMyDate IncreaseDateByOneMonth(stMyDate Date) {

   if(Date.Month == 12){
       Date.Month = 1;
       Date.Year++;
   }
   else {
       Date.Month++;
   }

   short NumberOfDausInCurrentMonth = NumberDaysInMonth(Date.Year, Date.Month);
   if (NumberOfDausInCurrentMonth < Date.Day)
       Date.Day = NumberOfDausInCurrentMonth;

    return Date;
}
stMyDate IncreaseDateByxMonths(stMyDate Date, short Months) {

    for (short i = 0; i < Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}
stMyDate IncreaseDateByOneYear(stMyDate Date) {

    Date.Year++;
    return Date;
}

stMyDate IncreaseDateByXYear(stMyDate Date, int Years) {

    for (int i = 0; i < Years; i++)
    {
            Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stMyDate IncreaseDateByXYearsFast(stMyDate Date, int Years) {

    Date.Year += Years;
    return Date;
}

stMyDate IncreaseDateByOneDecade(stMyDate Date) {

    Date.Year += 10;
    return Date;
}
stMyDate IncreaseDateByXDecades(stMyDate Date, short Decade) {

    for (int i = 0; i < Decade; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}
stMyDate IncreaseDateByXDecadesFast(stMyDate Date, short Decade) {

    Date.Year += Decade * 10;
    return Date;
}
stMyDate IncreaseDateByOneCentury(stMyDate Date) 
{
    // Period of 100 years
    Date.Year += 100;
    return Date;
}
stMyDate IncreaseDateByOneMillennium(stMyDate Date) {

    // Period of 1000 years
    Date.Year += 1000;
    return Date;
}
int main()
{
    stMyDate Date = ReadFullDate();
    cout << "\n\nDate After : \n\n";

    Date = IncreaseDateByOneDay(Date);
    printf("01-Adding One Day is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDay(Date,10);
    printf("02-Adding %d Day is : %d/%d/%d\n", 10,Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneWeek(Date);
    printf("03-Adding One Week is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXWeek(Date, 10);
    printf("04-Adding %d Weeks is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneMonth(Date);
    printf("05-Adding One Month is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByxMonths(Date, 5);
    printf("06-Adding %d Month is : %d/%d/%d\n", 5 ,Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneYear(Date);
    printf("07-Adding One Year is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXYear(Date, 10);
    printf("08-Adding %d Year is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXYearsFast(Date, 10);
    printf("09-Adding %d Year (fast) is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneDecade(Date);
    printf("10-Adding One Decade is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDecades(Date, 10);
    printf("11-Adding %d Decade is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByXDecadesFast(Date, 10);
    printf("12-Adding %d Decade (fast) is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneCentury(Date);
    printf("13-Adding One Century is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = IncreaseDateByOneMillennium(Date);
    printf("14-Adding One Millenniu is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
}

