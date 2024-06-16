#include <iostream>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string Msg) {
	int Number = 0;
	do {
		cout << Msg;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int RandomNummber(int From, int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
void FillArrayWithRandomNumber(int Array[100], int& LengthOfArray) {
	LengthOfArray = ReadPositiveNumber("Please Enter Number Of Array : ");
	for (int i = 0; i < LengthOfArray; i++)
		Array[i] = RandomNummber(1, 100);
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl;
}
void ReversedArray(int OriginalArr[100], int CopyArray[100], int ArrLength) {
	for (int i = 0; i < ArrLength; i++)
		CopyArray[i] = OriginalArr[ArrLength - 1 - i];
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	int Array1[100], Array2[100], int LengthOfArray = 0;

	FillArrayWithRandomNumber(Array1, LengthOfArray);
	cout << "\nArray Elements before Shuffle : \n";
	PrintArray(Array1, LengthOfArray);

	ReversedArray(Array1, Array2, LengthOfArray);
	cout << "\nArray 2 Elements coping array 1 in reversed order : \n";
	PrintArray(Array2, LengthOfArray);
	return 0;
}