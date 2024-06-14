
#include <iostream>
using namespace std;

void ReadNumber(int& Num1, int& Num2) {
    cout << "Enter Number 1 : ";
    cin >> Num1;
    cout << "Enter Number 2 : ";
    cin >> Num2;
}
void Swap(int& Num1, int& Num2){

    int TMP;
    TMP = Num1;
    Num1 = Num2;
    Num2 = TMP;
    cout << "\nAfter swap operation Numbers is " << endl;
}
void PrintNumber(int Num1, int Num2) {
    cout << "\nNumber 1 is " << Num1 << endl;
    cout << "\nNumber 2 is " << Num2 << endl;
}
int main()
{
    int Num1, Num2;
    ReadNumber(Num1, Num2);
    PrintNumber(Num1, Num2);
    Swap(Num1, Num2);
    PrintNumber(Num1, Num2);
}
