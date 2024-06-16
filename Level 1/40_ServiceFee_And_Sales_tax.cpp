
#include <iostream>
#include <cmath>
using namespace std;

enum enPrime_NotPrime { Prime = 1, Not_Prime = 2 };

float ReadNumber(string Msg) {
    float Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float CalculateTotalBill(int PriceService) {
    float TotalBill = PriceService * 1.1;
    TotalBill *= 1.16;
    return TotalBill;
}

void PrintPrimeOrNot(float PriceService) {

    cout << "The Total Bill is " << PriceService << endl;

}
int main()
{
    float PriceService = ReadNumber("Please Enter service price : ");
    PrintPrimeOrNot(CalculateTotalBill(PriceService));

}
