
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number =  0;
	do {
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void PrintDigits(int Number) {
	
	for (size_t i = Number; i > 0 ; i--)
	{
		for (int j = i; j > 0; j--) {
			cout << i;
		}
		cout << endl;
	}
}
int main()
{
	PrintDigits(ReadPositiveNumber("Please Enter Positive Number : "));
}
