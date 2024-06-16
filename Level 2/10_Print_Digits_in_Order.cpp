
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


int ReverseDigits(int Number) {
	int Remainder = 0, ReverseNumber = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReverseNumber = ReverseNumber * 10 + Remainder;
	}
	return ReverseNumber;
}
void PrintDigit(int ReverseNumber) {
	int Remainder = 0;
	while (ReverseNumber > 0)
	{
		Remainder = ReverseNumber % 10;
		ReverseNumber /= 10;
		cout << Remainder << endl;
	}
}
int main()
{
	PrintDigit(ReverseDigits(ReadPositiveNumber("Plese Enter Number : ")));
}
