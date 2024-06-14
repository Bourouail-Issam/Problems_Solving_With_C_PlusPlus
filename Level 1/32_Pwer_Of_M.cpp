
#include <iostream>
using namespace std; 

float ReadNumber() {
	float Base_Number;
	cout << "Enter Base Number : ";
	cin >> Base_Number;
	return Base_Number;
}
int ReadPower() {
	int Power;
	cout << "Enter Power Number : ";
	cin >> Power;
	return Power;
}
float Calc_Power_Of_BaseNumber(float BaseNumber , int Power) {

	float result = BaseNumber;

	for (int i = 1; i < Power; i++) {
		result *= BaseNumber;
	}
	return result;
}
void PrintPower_Of_BaseNumber(float Result) {
	cout << "\nResult is " << Result << endl;
}
int main()
{
	PrintPower_Of_BaseNumber(Calc_Power_Of_BaseNumber(ReadNumber(), ReadPower()));
}

