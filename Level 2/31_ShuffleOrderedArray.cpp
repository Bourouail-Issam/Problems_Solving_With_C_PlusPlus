#include <iostream>
#include <cmath>
using namespace std;
enum enPrime_NotPrime { Prime = 1, Not_Prime = 2 };
enPrime_NotPrime PrimeNumber(int number) {
	int HalfNumber = round(number / 2);
	for (int i = 2; i < HalfNumber; i++) {
		if (number % i == 0)
			return enPrime_NotPrime::Not_Prime;
	}
	return enPrime_NotPrime::Prime;
}
int ReadPositiveNumber(string Msg) {
	int Number = 0;
	do {
		cout << Msg;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
void Sawp(int& A, int& B) {
	int TMP = 0;
	TMP = A;
	A = B;
	B = TMP;
}
int RandomNummber(int From, int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
void FillArrayWith_1To_N(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		Array[i] = i + 1;
}
void ShuffleArray(int Arr[100], int ArrLength) {
	for (int i = 0; i < ArrLength; i++)
		Sawp(Arr[RandomNummber(1, ArrLength) - 1], Arr[RandomNummber(1, ArrLength) - 1]);
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";	
	cout << endl;
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	int Array[100];
	int LengthOfArray = ReadPositiveNumber("Please Enter Number Of Array : ");
	FillArrayWith_1To_N(Array, LengthOfArray);
	cout << "\nArray Elements before Shuffle : \n";
	PrintArray(Array, LengthOfArray);
	ShuffleArray(Array, LengthOfArray);
	cout << "\nArray Elements After Shuffle : \n";
	PrintArray(Array, LengthOfArray);	
	return 0;
}

