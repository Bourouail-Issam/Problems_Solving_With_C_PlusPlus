
#include <iostream>
#include <cmath>
using namespace std;

float ReadCircumference() {
	float circumference;
	cout << "<< Program to calculate Circle Area along The circumference >> \n\n";
	cout << "Please Enter circumference : ";
	cin >> circumference;
	return circumference;
}
float CalculateCircleAreaByCircumference(float circumference) {
	float PI = 3.141592653589793238;
	return pow(circumference,2)*(4*PI);
}
void PrintResult(float CircleArea) {
	cout << "\nCircle Area is " << CircleArea << endl;
}
int main()
{
	PrintResult(CalculateCircleAreaByCircumference(ReadCircumference()));
}
