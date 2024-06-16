
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

	for (size_t i = 65; i <= (65 + Number - 1); i++)
	{
		for (int j = 65 ; j <= i ; j++) {
			cout << char(i);
		}
		cout << endl;
	}
}
int main()
{
	PrintDigits(ReadPositiveNumber("Please Enter Positive Number : "));
}
