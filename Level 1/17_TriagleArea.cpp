
#include <iostream>
#include <cmath>
using namespace std;

void ReadValue(float& BaseTriangle, float& heightTriangle) {

	cout << "<< Program to calculate Triangle Area >> \n\n";

	cout << "Please Enter value of Base Triangle : ";
	cin >> BaseTriangle;

	cout << "Please Enter value of height Triangle : ";
	cin >> heightTriangle;
}
float CalculateTriangleArea(float BaseTriangle, float heightTriangle) {

	return (BaseTriangle * heightTriangle)/2;
}
void PrintTriangleArea(float TriangleArea) {

	cout << "\nTriangle Area is " << TriangleArea << endl;
}
int main()
{
	float BaseTriangle, heightTriangle;

	ReadValue(BaseTriangle, heightTriangle);
	PrintTriangleArea(CalculateTriangleArea(BaseTriangle, heightTriangle));

	return 0;
}
