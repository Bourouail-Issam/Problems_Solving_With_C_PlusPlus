
#include <iostream>
using namespace std; 

float ReadNumber() {
	float Base_Number;
	cout << "Enter Base Number : ";
	cin >> Base_Number;
	return Base_Number;
}
void printPower_Of_2_3_4(float BaseNumber) {
	cout << BaseNumber << "^2 = " << BaseNumber * BaseNumber <<endl;
	cout << BaseNumber << "^3 = " << BaseNumber * BaseNumber * BaseNumber << endl;
	cout << BaseNumber << "^4 = " << BaseNumber * BaseNumber * BaseNumber * BaseNumber << endl;
}
int main()
{
	printPower_Of_2_3_4(ReadNumber());

	return 0;
}

