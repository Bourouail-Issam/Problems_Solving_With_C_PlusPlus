
#include <iostream>
#include <cmath>
using namespace std;

float ReadInscribed_Square() {
	float Inscribed_Square;
	cout << "<< Program to calculate Circle Area Inscribed in a Square >> \n\n";
	cout << "Please Enter Square side : ";
	cin >> Inscribed_Square;
	return Inscribed_Square;
}
float CalculateCircleAreaInscribed_Square(float Inscribed_Square) {
	float PI = 3.141592653589793238;
	return (PI * pow(Inscribed_Square, 2)) / 4;
}
void PrintCircleAreaInscribed_Square(float CircleArea) {
	cout << "\nCircle Area is " << CircleArea << endl;
}
int main()
{
	PrintCircleAreaInscribed_Square(CalculateCircleAreaInscribed_Square(ReadInscribed_Square()));
}
