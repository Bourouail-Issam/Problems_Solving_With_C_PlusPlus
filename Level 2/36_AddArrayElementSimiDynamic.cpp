#include <iostream>
using namespace std;
int ReadNumber() {
	int Number = 0;
	cout << "\Please Enter a number : ";
	cin >> Number;
	return Number;
}
void AddArrayElement(int Number,int Arr[100], int &ArrLength) {
	Arr[ArrLength] = Number;
	ArrLength++;
}
void inputUserNumbersInArray(int Arr[100], int& ArrLength) {
	bool AddMore= true;
	do{
		AddArrayElement(ReadNumber(), Arr, ArrLength);
		cout << "Do you want add more number [0]:No , [1]:Yes : ";
		cin >> AddMore;
	} while (AddMore == 1);
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl << endl;
}
int main() {
	int Array[100], ArrLength = 0;
	inputUserNumbersInArray(Array, ArrLength);

	cout << "\nArray length : " << ArrLength;

	cout << "\nArray Elements: ";
	PrintArray(Array, ArrLength);
	return 0;
}
