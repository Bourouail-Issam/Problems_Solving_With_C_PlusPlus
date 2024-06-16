
#include <iostream>
using namespace std;

float ReadPositiveNumber(string Msg) {
	float Number = 0;
	do {
		cout << Msg;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int TotalMonths(float LoanAmount, float MonthlyPayment) {
	return (int)LoanAmount / MonthlyPayment;
}
int main()
{
	float  LoanAmount = ReadPositiveNumber("Please Enter The Loan Amount you want : ");
	float  MonthlyPayment = ReadPositiveNumber("Please Enter Monthly Payment: ");
	cout << "\nYou need " << TotalMonths(LoanAmount, MonthlyPayment)
		 << " Months to repay the Loan\n";
}

