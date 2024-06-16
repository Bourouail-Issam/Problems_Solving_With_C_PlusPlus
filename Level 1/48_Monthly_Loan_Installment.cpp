
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
int MonthlyPayment(float LoanAmount, float Months) {
	return (int)LoanAmount / Months;
}
int main()
{
	float  LoanAmount = ReadPositiveNumber("Please Enter The Loan Amount you want : ");
	float  Months = ReadPositiveNumber("How Many Months You Need to settle The Loan : ");
	cout << "\nYou need To pay  " << MonthlyPayment(LoanAmount, Months)
		<< " Per Months \n";
}

