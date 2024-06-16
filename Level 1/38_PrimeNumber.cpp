
#include <iostream>
#include <cmath>
using namespace std;

enum enPrime_NotPrime { Prime = 1, Not_Prime = 2 };

int ReadNumber(string Msg) {
    int Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

enPrime_NotPrime checkPrime(int Number) {

    int HalfNumber = round(Number / 2);

    for (int i = 2; i <= HalfNumber; i++) {

        if (Number % i == 0)
            return enPrime_NotPrime::Not_Prime;
    }
    return enPrime_NotPrime::Prime;
}

void PrintPrimeOrNot(int NB) {

    if (checkPrime(NB) == enPrime_NotPrime::Prime)
        cout << "\nthe Number " << NB << " Prime\n";
    else
        cout << "\nthe Number " << NB << " Not Prime\n";

}
void PrintPrimeOrNotUaeSwitch(int NB) {

    switch (checkPrime(NB))
    {
    case enPrime_NotPrime::Prime:
        cout << "\nthe Number " << NB << " Prime\n";
        break;
    case enPrime_NotPrime::Not_Prime:
        cout << "\nthe Number " << NB << " Not Prime\n";
        break;
    }

}
int main()
{
    int NB = ReadNumber("Please Enter a Positive Number : ");
    PrintPrimeOrNot(NB);

}
