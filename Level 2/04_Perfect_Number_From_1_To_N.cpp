
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
void PrintPerfectNumberFrom1ToN(int Number) {
	for (int i = 1; i <= Number; i++) {
		if (IsPerfectNumber(i))
			cout << endl << i << " is Perfect Number\n";
	}
}
int main()
{
	PrintPerfectNumberFrom1ToN(ReadPositiveNumber("Please Enter Number : "));
}
