#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float number = 0;
	cout << "Please Enter Number : ";
	cin >> number;
	return number;
}

double calculatePower(double base, float exponent) {

	if (base == 0) return 0;

	return exp(log(base) * exponent);
}
double MySqrt(float number)
{
	return calculatePower(number, .5);
}

int main()
{
	float number = ReadNumber();
	cout << "\nMy Floor : " << MySqrt(number) << endl;
	cout << "\nC++ floor Result : " << sqrt(number) << endl;
	return 0;
}
