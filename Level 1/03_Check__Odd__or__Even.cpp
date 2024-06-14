
#include <iostream>
using namespace std;

enum enTypeNumber {Odd = 1, Even = 2};
int readNumber() 
{
    int number;
    cout << "Please enter a whole number (integer) : ";
    cin >> number;
    return number;
}
enTypeNumber checkOddOrEven(int num) {
    int result = num % 2;
    if (result) 
    {
        return enTypeNumber::Odd;
    }
    else 
    {
        return enTypeNumber::Even;
    }
}
void printResult(enTypeNumber result) {

    if (result == enTypeNumber::Odd) 
    {
        cout << "\nthe number is Odd \n";
    }
    else
    {
        cout << "\nthe number is even \n";
    }
}

int main()
{
    printResult(checkOddOrEven(readNumber()));
    return 0;
}
