
#include <iostream>
using namespace std;

float ReadTotalSales(string Msg) {
	float TotalSales;

	cout << Msg;
	cin >> TotalSales;

	return TotalSales;
}
float checkCommission(float TotalSales) {

	if (TotalSales >= 1000000)
		return 0.01;
	if (TotalSales >= 500000)
		return 0.02;
	if (TotalSales >= 100000)
		return 0.03;
	if (TotalSales >= 50000)
		return 0.05;
	else
		return 0.00;
}
float Calc_Commission(float TotalSalse) {

	return TotalSalse * checkCommission(TotalSalse);
	 
}
void PrintCommission(float TotalSales) {
	cout << "The Commission for "<<TotalSales<< " is "<< Calc_Commission(TotalSales) << "\n\n";
}
int main()
{
	PrintCommission(ReadTotalSales("Please Enter Total Sales : "));
	return 0;
}

