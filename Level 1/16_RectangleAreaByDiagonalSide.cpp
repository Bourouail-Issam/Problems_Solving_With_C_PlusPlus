
#include <iostream>
#include <cmath>
using namespace std;

void ReadValue(float& throughDiagonal, float& sideArea) {

	cout << "<< Program to calculate Rectangle Area >> \n";

	cout << "Please Enter value of through Diagonal : ";
	cin >> throughDiagonal;

	cout << "Please Enter value of side Area : ";
	cin >> sideArea;
}
float CalculateRectangleArea(float throughDiagonal, float sideArea) {

	return sideArea * sqrt(pow(throughDiagonal, 2) - pow(sideArea, 2));
}
void PrintRectangleArea(float RectangleArea) {

	cout << "\nRectangle Area is " << RectangleArea << endl;
}
int main()
{
	float throughDiagonal,sideArea ;

	ReadValue(throughDiagonal, sideArea);
	PrintRectangleArea(CalculateRectangleArea(throughDiagonal, sideArea));

	return 0;
}
