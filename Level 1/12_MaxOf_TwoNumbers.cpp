
#include <iostream>
using namespace std;

void ReadNumber(int& Num1, int& Num2) {
    cout << "Print Number 1 : ";
    cin >> Num1;
    cout << "Print Number 2 : ";
    cin >> Num2;
}

int checkMaxOf_TwoNumbers(int Num1, int Num2) {
    if (Num1 > Num2)
        return Num1;
    else 
        return Num2;
}
void PrintMaxOf2numbers(int MaxNumber) {
    cout << "\nMax Number is " << MaxNumber << endl;
}
int main()
{
    int Num1, Num2;
    ReadNumber(Num1, Num2);
    PrintMaxOf2numbers(checkMaxOf_TwoNumbers(Num1, Num2));
}

