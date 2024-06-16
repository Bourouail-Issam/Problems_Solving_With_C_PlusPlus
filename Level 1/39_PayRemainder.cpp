
#include <iostream>
#include <cmath>
using namespace std;

enum enPrime_NotPrime { Prime = 1, Not_Prime = 2 };

float ReadNumber(string Msg) {
    int Number = 0;
    do {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

float CalculateRemainder(int TotalBill, int CashPaid) {
    return  CashPaid - TotalBill;
}

void PrintPrimeOrNot(int remainder) {
  
    if (remainder < 0)
        cout << "You Still Need To Pay " << remainder << endl;
    else
        cout << "The remainder after deduction is " << remainder << endl;
}
int main()
{
    float TotalBill = ReadNumber("Please Enter a Total Bill : ");
    float CashPaid = ReadNumber("Please Enter a Cash Paid : ");
    PrintPrimeOrNot(CalculateRemainder(TotalBill, CashPaid));

}
