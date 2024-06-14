
#include <iostream>
#include <cmath>
using namespace std;

void ReadCircumference(float& BaseTriangle, float& SideTriangle) {
	
	cout << "<< Program to calculate Circle Area Inscribed in an Isosceles Triangle >> \n\n";
	cout << "Please Enter Base Triangle : ";
	cin >> BaseTriangle;
	cout << "Please Enter Side Triangle : ";
	cin >> SideTriangle;
}
float CalculateCircleAreaInscribedTriangle(float BaseTriangle, float SideTriangle) {
	float PI = 3.141592653589793238;
	float Area = ((PI * pow(BaseTriangle, 2)) / 4) * ((2 * SideTriangle - BaseTriangle) / (2 * SideTriangle + BaseTriangle));
	return Area;
}
void PrintResult(float CircleArea) {
	cout << "\nCircle Area is " << CircleArea << endl;
}
int main()
{
	float BaseTriangle,SideTriangle;
	ReadCircumference(BaseTriangle, SideTriangle);
	PrintResult(CalculateCircleAreaInscribedTriangle(BaseTriangle, SideTriangle));
}
