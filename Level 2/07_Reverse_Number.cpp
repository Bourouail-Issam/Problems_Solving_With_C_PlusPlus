
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


void ReverseDigits(int Number) {
	int Remainder = 0, ReverseNumber = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReverseNumber = ReverseNumber * 10 + Remainder;
	}
	cout << "Reverse Number  = " << ReverseNumber;
}
int main()
{
	ReverseDigits(ReadPositiveNumber("Please Enter Number : "));
}
