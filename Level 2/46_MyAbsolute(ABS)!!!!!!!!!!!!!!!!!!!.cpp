#include <iostream>
#include <cmath>
using namespace std;
int ReadNumber(string Msg) {
	int number = 0;
	cout << Msg;
	cin >> number;
	return number;
}

int MyABS(int number) {
	if (number < 0)
		return number * -1;
	else
		return number;
}
int main() {
	int number = ReadNumber("Please Enter Number : ");
	cout << "\nMy abs Result : " << MyABS(number) << endl;
	cout << "\nC++ Built-in function abs Result : " << abs(number) << endl;
	return 0;
}
