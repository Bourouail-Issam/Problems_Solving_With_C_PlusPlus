
#include <iostream>
#include <cmath>
using namespace std;

void ReadCircumference(float& a, float& c, float& b) {

	cout << "<< Program to calculate Circle Area Inscribed in an Isosceles Triangle >> \n\n";
	cout << "Please Enter Side Triangle 1 : ";
	cin >> a;
	cout << "Please Enter Side Triangle 2 : ";
	cin >> c;
	cout << "Please Enter Base Triangle : ";
	cin >> b;
}
float CalculateCircleAreaInscribedTriangle(float a, float c, float b) {
	float PI = 3.141592653589793238;
	float p = (a + c + b)/2;
	float T = (a * b * c) / (4 * sqrt(p * (p - a)*(p - b)*(p - c) ));
	float Area = PI*pow(T,2);
	return Area;
}
void PrintResult(float CircleArea) {
	cout << "\nCircle Area is " << CircleArea << endl;
}
int main()
{
	float a, c, b;
	ReadCircumference(a, c, b);
	PrintResult(CalculateCircleAreaInscribedTriangle(a, c, b));
}
