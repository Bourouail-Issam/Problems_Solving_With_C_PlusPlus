#include <iostream>
#include <cmath>
using namespace std;
int ReadPositiveNumber(string Msg) {
	int number = 0;
	do {
		cout << Msg;
		cin >> number;
	} while (number <= 0);
	return number;
}
int Random(int From, int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
void FillArray(int  Arr[100], int& Arraylength) {
	Arraylength = ReadPositiveNumber("Please Enter Number of Array : ");
	for (int i = 0; i < Arraylength; i++)
	{
		Arr[i] = Random(1, 100);
	}
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl << "\n";
}
int CountEvenNumberInArray(int ArrSource[100], int SourceLength) {
	int counter = 0;
	for (int i = 0; i < SourceLength; i++) {
		if (ArrSource[i] % 2 == 0)
			counter++;
	}
	return counter;
}
int main() {

	srand((unsigned)time(NULL));
	int ArrSource[100], SourceLength = 0;

	FillArray(ArrSource, SourceLength);

	cout << "\nArray 1 Elements: ";
	PrintArray(ArrSource, SourceLength);

	cout << "Odd Numbers count is : " << CountEvenNumberInArray(ArrSource, SourceLength) << endl;
	return 0;
}
