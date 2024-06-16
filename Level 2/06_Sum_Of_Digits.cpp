
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
	int Remainder = 0 , Sum = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Sum += Remainder;
	}
	cout << "Sum of Digits = " << Sum;
}
int main()
{
	PrintDigits_ReversedOrder(ReadPositiveNumber("Please Enter Number : "));
}
