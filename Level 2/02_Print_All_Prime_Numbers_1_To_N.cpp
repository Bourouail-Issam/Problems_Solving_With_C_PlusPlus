
#include <iostream>
#include <cmath>
using namespace std;

enum enPrime_NotPrime { Prime = 1, Not_Prime = 2 };

int ReadPositiveNumber(string Msg) {
    int Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

enPrime_NotPrime checkPrime(int Number) {
    
    int HalfNumber = round(Number / 2);
    for (int counter = 2; counter <= HalfNumber; counter++)
    {
        if (Number % counter == 0)
        {
            return enPrime_NotPrime::Not_Prime;
        }
    }
    return enPrime_NotPrime::Prime;
}

void PrintPrimeNumbers(int PositiveNumber) {

    cout << "Prime Number From 1 To " << PositiveNumber << " are : \n";
    for (int i = 1; i <= PositiveNumber; i++) 
    {
        if (checkPrime(i) == enPrime_NotPrime::Prime)
            cout << i <<"\n";
    }
}
int main()
{
    int PositiveNumber = ReadPositiveNumber("Please Enter a Positive Number : ");
    PrintPrimeNumbers(PositiveNumber);

}

