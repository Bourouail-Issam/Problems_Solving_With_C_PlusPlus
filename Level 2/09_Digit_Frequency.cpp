
#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;
	do {
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}


int CoutDigitFrequency(int Digit, int Number) {
	int Remainder = 0, counter = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		if (Digit == Remainder)
			counter++;
	}
	return counter;
}

void PrintAllDigitsFrequency(int number) {
	short checkDigitFrequency = 0;
	for (int i = 1; i < 10; i++) {
		checkDigitFrequency = CoutDigitFrequency(i, number);
		if (checkDigitFrequency > 0)
			cout << "\nDigit " << i << " Frequency is " << checkDigitFrequency << " Times(s)\n";
	}
}
int main()
{
	PrintAllDigitsFrequency(ReadPositiveNumber("Please Enter The Number : "));
}
