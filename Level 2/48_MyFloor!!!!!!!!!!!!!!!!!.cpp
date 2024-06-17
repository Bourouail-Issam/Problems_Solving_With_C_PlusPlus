#include <iostream>
#include <cmath>
using namespace std;
float ReadNumber() {
	float number = 0;
	cout << "Please Enter Number : ";
	cin >> number;
	return number;
}

int MyFloor(float number) {
	if (number > 0) {
		return (int)number;
	}
	else
	    return (int)number -1;
}
int main() {
	float number = ReadNumber();
	cout << "\nMy Floor : " << MyFloor(number) << endl;
	cout << "\nC++ floor Result : " << floor(number) << endl;
	return 0;
}
