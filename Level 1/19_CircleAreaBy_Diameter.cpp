
#include <iostream>
#include <cmath>
using namespace std;

float ReadDiameter() {
	float Diameter;
	cout << "<< Program to calculate Circle Area By Diameter >> \n\n";
	cout << "Please Enter Diameter : ";
	cin >> Diameter;
	return Diameter;
}
float CalculateCircleAreaByDiameter(float Diameter) {
	float PI = 3.141592653589793238;
	return (PI * pow(Diameter, 2))/4;
}
void PrintCircleAreaByDiameter(float CircleArea) {
	cout << "\nCircle Area is " << CircleArea << endl;
}
int main()
{
	PrintCircleAreaByDiameter(CalculateCircleAreaByDiameter(ReadDiameter()));
}
