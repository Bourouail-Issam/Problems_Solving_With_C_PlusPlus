
#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;
	do {
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}


void PrintDigits_ReversedOrder(int Number) {
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		cout << Remainder << endl;
	}
}
int main()
{
	PrintDigits_ReversedOrder(ReadPositiveNumber("Please Enter Number : "));
}
