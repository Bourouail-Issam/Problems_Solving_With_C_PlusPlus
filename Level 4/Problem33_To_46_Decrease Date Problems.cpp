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

bool IsLeapYear(short Year) {
    return (0 == Year % 400 || (0 == Year % 4 && 0 != Year % 100));
}
short NumberDaysInMonth(short Year, short Month) {
    if (Month <= 0 || Month > 12)
        return 0;
    short NumberDaysinMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberDaysinMonth[Month - 1]);
}

stMyDate DecreaseDateByOneDay(stMyDate Date) 
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberDaysInMonth(Date.Year, Date.Month);;
        }
    }
    else {
        Date.Day--;
    }
    return Date;
}
stMyDate DecreaseDateByXeDay(stMyDate Date, short Days) 
{
    for (short i = 0; i < Days; i++)
        Date = DecreaseDateByOneDay(Date);

    return Date;
}
stMyDate DecreaseDateByOneWeek(stMyDate Date)
{
    for (short i = 0; i < 7; i++)
        Date = DecreaseDateByOneDay(Date);

    return Date;
}
stMyDate DecreaseDateByXWeeks(stMyDate Date, short Weeks)
{
    for (short i = 0; i < Weeks; i++)
        Date = DecreaseDateByOneWeek(Date);

    return Date;
}
stMyDate DecreaseDateByOneMonth(stMyDate Date)
{
    if (Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
    }
    else{
        Date.Month--;
    }

    short NumberOfDausInCurrentMonth = NumberDaysInMonth(Date.Year, Date.Month);

    if (NumberOfDausInCurrentMonth < Date.Day )
        Date.Day = NumberOfDausInCurrentMonth;
    
    return Date;
}
stMyDate DecreaseDateByXMonths(stMyDate Date, short Months)
{
    for (short i = 0; i < Months; i++)
        Date = DecreaseDateByOneMonth(Date);

    return Date;
}
stMyDate DecreaseDateByOneYear(stMyDate Date)
{
    Date.Year--;
    return Date;
}
stMyDate DecreaseDateByXYears(stMyDate Date, short Years)
{
    for (short i = 0; i < Years; i++)
        Date = DecreaseDateByOneYear(Date);

    return Date;
}
stMyDate DecreaseDateByXYearsFast(stMyDate Date, short Years)
{
    Date.Year -= Years;
    return Date;
}
stMyDate DecreaseDateByOneDecade(stMyDate Date)
{
    Date.Year -= 10;
    return Date;
}
stMyDate DecreaseDateByXDecade(stMyDate Date, short Decade)
{
    for (short i = 0; i < Decade; i++)
        Date = DecreaseDateByOneDecade(Date);

    return Date;
}
stMyDate DecreaseDateByXDecadeFast(stMyDate Date, short Decade)
{
    Date.Year -= Decade * 10;
    return Date;
}
stMyDate DecreaseDateByOneCentury(stMyDate Date)
{
    Date.Year -= 100;
    return Date;
}
stMyDate DecreaseDateByOneMillennium(stMyDate Date)
{
    Date.Year -= 1000;
    return Date;
}
int main()
{
    stMyDate Date = ReadFullDate();
    cout << "\n\nDate After : \n\n";

    Date = DecreaseDateByOneDay(Date);
    printf("01-Subtraction One Day is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXeDay(Date,10);
    printf("02-Subtraction %d Day is : %d/%d/%d\n", 10,Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneWeek(Date);
    printf("03-Subtraction One Week is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXWeeks(Date, 10);
    printf("04-Subtraction %d Weeks is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneMonth(Date);
    printf("05-Subtraction One Month is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXMonths(Date, 5);
    printf("06-Subtraction %d Months is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneYear(Date);
    printf("07-Subtraction One Year is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXYears(Date, 10);
    printf("08-Subtraction %d Years is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXYearsFast(Date, 10);
    printf("08-Subtraction %d Years (Fast) is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneDecade(Date);
    printf("00-Subtraction One decade is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXDecade(Date, 10);
    printf("11-Subtraction %d decade is : %d/%d/%d\n",10 ,Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByXDecadeFast(Date, 10);
    printf("11-Subtraction %d decade is : %d/%d/%d\n", 10, Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneCentury(Date);
    printf("11-Subtraction One Century is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);

    Date = DecreaseDateByOneMillennium(Date);
    printf("11-Subtraction One Millennium is : %d/%d/%d\n", Date.Day, Date.Month, Date.Year);
}
