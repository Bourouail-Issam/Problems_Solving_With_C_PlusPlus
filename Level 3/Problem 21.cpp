#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


void PrintFibonacciSeries ( int NumberFibo) {
	int Priv1 = 1, Priv2 = 0, FebNumber = 0;
	cout << "1   ";
	for (int i = 2; i <= NumberFibo; i++) {

		FebNumber = Priv1 + Priv2;
		cout << FebNumber << setw(5);
		Priv2 = Priv1;
		Priv1 = FebNumber;
	}
}

int main() {

	cout << "\nFibonacci Series of 10 :\n";
	PrintFibonacciSeries(10);
	
	return 0;
}

