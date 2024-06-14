
#include <iostream>
using namespace std;
struct strMyMoney
{
	int Penny,Nickel, Dime, Quarter, Dollar;
};
strMyMoney ReadBigBankContent() {

	strMyMoney Money;
	cout << "Please Enter Number Pennies : ";
	cin >> Money.Penny;
	cout << "Please Enter Number Nickels : ";
	cin >> Money.Nickel;
	cout << "Please Enter Number Dimes : ";
	cin >> Money.Dime;
	cout << "Please Enter Number Quarters : ";
	cin >> Money.Quarter;
	cout << "Please Enter Number Dollar : ";
	cin >> Money.Dollar;
	return Money;
}

int Calc_Total_Pennies(strMyMoney Money) {
	return Money.Penny + Money.Nickel * 5 + Money.Dime * 10 + Money.Quarter * 25 + Money.Dollar * 100;
	 
}
void PrintTotal_Pennies_Dollar(int TotalPennies) {
	cout << TotalPennies << " Pennies \n";
	cout << (float) TotalPennies / 100 << " Dollars" << endl;
}
int main()
{
	int TotalPennies = Calc_Total_Pennies(ReadBigBankContent());
	PrintTotal_Pennies_Dollar(TotalPennies);

	return 0;
}

