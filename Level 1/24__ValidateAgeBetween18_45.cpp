
#include <iostream>
#include <cmath>
using namespace std;

int ReadAge() {

	short unsigned Age;
	cout << "<< Program to calculate Circle Area Inscribed in an Isosceles Triangle >> \n\n";
	cout << "Please Enter Your Age : ";
	cin >> Age;
	return Age;
}
bool ValidationBetween18_45(int Age) {
	return (Age>=18 && Age<=45);
}
void PrintResult(bool Age) {
	if (Age)
		cout << Age << "Valid Age \n";
	else
		cout<< Age << "Invalid Age \n";
}
int main()
{
	PrintResult(ValidationBetween18_45(ReadAge()));
	return 0;
}
