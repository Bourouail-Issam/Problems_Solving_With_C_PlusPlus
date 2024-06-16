
#include <iostream>
#include <cmath>

using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;
	do {
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

bool IsPerfectNumber(int Number) {

	int Test_Perfect_Number = 0;
	for (int i = 1; i < Number; i++) {
		if (Number % i == 0)
			Test_Perfect_Number += i;
	}
	return Test_Perfect_Number == Number;
}
void Print_Perfect_Number(int Number) {

	if (IsPerfectNumber(Number))
		cout << endl << Number << " is Perfect \n";
	else
		cout << endl << Number << " is Not Perfect\n";
}
int main()
{
	Print_Perfect_Number(ReadPositiveNumber("Please Enter Number : "));
}
