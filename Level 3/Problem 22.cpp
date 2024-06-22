#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


void PrintFibonacciUsingRecurssion(int Number, int Priv1, int Priv2) {
	int NumberFibo = 0;
	if (Number > 0)
	{
		NumberFibo = Priv1 + Priv2;
		cout << NumberFibo << "   ";
		Priv2 = Priv1;
		Priv1 = NumberFibo;
		PrintFibonacciUsingRecurssion(Number - 1, Priv1, Priv2);
	}
}

int main() {

	cout << "\nFibonacci Series of 10 :\n";
	PrintFibonacciUsingRecurssion(10,0,1);

}

