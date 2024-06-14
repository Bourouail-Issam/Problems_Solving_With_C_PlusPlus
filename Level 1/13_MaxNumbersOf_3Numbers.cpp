
#include <iostream>
using namespace std;

void ReadeNumbers(int& Num1, int& Num2, int& Num3) {
	cout << "Enter Number 1 : ";
	cin >> Num1;
	cout << "Enter Number 2 : ";
	cin >> Num2;
	cout << "Enter Number 3 : ";
	cin >> Num3;
}
int CheckMaxNumberOf3(int Num1, int Num2, int Num3) {

	if (Num1 > Num2)
		if (Num1 > Num3)
			return Num1;
		else
			return Num3;
	else
		if (Num2 > Num3)
			return Num2;
		else
			Num3;
}
void PrintMaxNumber(int MaxNumber) {
	cout << "\nThe Max Number is " << MaxNumber << endl;
}
int main()
{
	int Num1, Num2, Num3;
	ReadeNumbers(Num1, Num2, Num3);
	PrintMaxNumber(CheckMaxNumberOf3(Num1, Num2, Num3));
}
