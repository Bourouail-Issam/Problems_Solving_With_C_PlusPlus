
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

void PrintDigits(int Number) {

	for (size_t i = Number; i >=1 ; i--)
	{
		for (int j = i; j > 0; j--) {
			cout << char(64 + i);
		}
		cout << endl;
	}
}
int main()
{
	PrintDigits(ReadPositiveNumber("Please Enter Positive Number : "));
}
