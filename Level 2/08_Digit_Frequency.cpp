
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


int CountDigitFrequency(short DigitToCheck, int Number) {
	int Remainder = 0 , counter = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		if (Remainder == DigitToCheck)
			counter++;
	}
	return counter;
}
int main()
{
	int Number = ReadPositiveNumber("Please Enter The Main Number : ");
	short DigitToCheck = ReadPositiveNumber("Please Enter one Digit to check ? : ");

	cout << "\ndigit " << DigitToCheck << " Frequency is "
		 <<CountDigitFrequency(DigitToCheck, Number)
		 << " Time(s)\n" ;
}
