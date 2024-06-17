#include <iostream>
#include <cmath>
using namespace std;
enum enPrime_NotPrime { Prime = 1, Not_Prime = 2 };
int ReadNumber() {
	int Number = 0;
	cout << "\Please Enter a number : ";
	cin >> Number;
	return Number;
}
int RandomNumber(int From, int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
enPrime_NotPrime checkPrime(int Number) {
	int HalfNumber = round(Number / 2);
	for (int i = 2; i <= HalfNumber; i++) {
		if (Number % i == 0)
			return enPrime_NotPrime::Not_Prime;
	}
	return enPrime_NotPrime::Prime;
}
void AddArrayElement(int Number, int Arr[100], int& ArrLength) {
	Arr[ArrLength] = Number;
	ArrLength++;
}
void FillArrayWithRandomNumber(int Arr[100], int& ArrLength) {
	ArrLength = ReadNumber();
	for (int i = 0; i < ArrLength; i++) {
		Arr[i] = RandomNumber(1, 100);
	}
}
void CopyPrimeNumbers(int OriginalArr[100], int CopyArr[100], int ArrLength1, int& ArrLength2) {
	for (int i = 0; i < ArrLength1; i++) {
		if (checkPrime(OriginalArr[i]) == enPrime_NotPrime::Prime)
			AddArrayElement(OriginalArr[i], CopyArr, ArrLength2);
	}
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl << endl;
}
int main() {

	srand((unsigned)time(NULL));
	int Arr1[100], ArrLength1 = 0, Arr2[100], ArrLength2 = 0;
	FillArrayWithRandomNumber(Arr1, ArrLength1);
	cout << "\nArray 1 Elements: ";
	PrintArray(Arr1, ArrLength1);
	CopyPrimeNumbers(Arr1, Arr2, ArrLength1, ArrLength2);

	cout << "\nArray 2 Elements: ";
	PrintArray(Arr2, ArrLength2);
	return 0;
}
