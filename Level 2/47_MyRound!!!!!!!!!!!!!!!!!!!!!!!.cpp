#include <iostream>
#include <cmath>
using namespace std;
float ReadNumber(string Msg) {
	float number = 0;
	cout << Msg;
	cin >> number;
	return number;
}

float MyABS(float number) {
	if (number < 0)
		return number * -1;
	else
		return number;
}

float GetFractionPart(float number) {
	return number - (int)number;
}

int MyRound(float number) {
	int IntPart = (int)number;
	float FractionPart = GetFractionPart(number);
	
	if (MyABS(FractionPart) > .5) 
	{
		if (number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}
int main() {
    float number = ReadNumber("Please Enter Number : ");
	cout << "\nMy Round : " << MyRound(number) << endl;
	cout << "\nC++ round Result : " << round(number) << endl;
	return 0;
}
