
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;
	do {
		cout << Message;
		cin >> Number;
	}
	while (Number <= 0);
	return Number;
}
int ReverseNumber(int Number) {
	int Remainder = 0, ReverseNumber = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		ReverseNumber = ReverseNumber * 10 + Remainder;
	}
	return ReverseNumber;
}
void PrintPalindromeOrNot(int Number) {

	if (ReverseNumber(Number) == Number)
		cout << endl << "Yes , it is a Palindrome number.\n";
	else
		cout << endl << "No , it is NOT a Palindrome number.\n";
}
int main()
{
	PrintPalindromeOrNot(ReadPositiveNumber("Please enter a positive number : "));
}

