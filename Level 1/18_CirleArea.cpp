
#include <iostream>
#include <cmath>
using namespace std;

float ReadValue() {
	float radios;
	cout << "<< Program to calculate Circle Area >> \n\n";

	cout << "Please Enter radios : ";
	cin >> radios;

	return radios;
}
float CalculateCircleArea(float r) {
	float PI = 3.141592653589793238;
	return  PI * pow(r, 2);
}
void PrintCircleArea(float CircleArea) {
	cout << "\nCircle Area is " << CircleArea << endl;
}
int main()
{
	PrintCircleArea(CalculateCircleArea(ReadValue()));
}
