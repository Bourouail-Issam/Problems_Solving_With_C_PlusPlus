 #include <iostream>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Please enter Year : ";
    cin >> number;
    return number;
}
bool checkLeapYear(int number)
{
    if (number % 400 == 0)
        return true;
    if (0 == number % 400 )
        return false;
    if (0 == number % 4)
        return true;
    else
        return false;
}
int main()
{
    int Year = ReadNumber();
    if (checkLeapYear(Year))
        cout << "\n Yes, Year" << Year << " it's Leap Year\n";
    else
        cout << "\n Yes, Year" << Year << " it's not Leap Year\n";


}


