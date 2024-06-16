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
int RandomNummber(int From, int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
void FillArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		Array[i] = RandomNummber(1, 100);
}
void  SumTowArray(int FirstArray[100], int SecondArray[100], int SumArray[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
	{
		SumArray[i] = FirstArray[i] + SecondArray[i];
	}
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++){
		cout << Array[i] << " ";
	}
	cout << endl;
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	int Array1[100], Array2[100], SumArray[100];
	int LengthOfArray = ReadPositiveNumber("Please Enter Number Of Array : ");

	FillArray(Array1, LengthOfArray);
	FillArray(Array2, LengthOfArray);

	cout << "\nArray1 Elements : \n";
	PrintArray(Array1, LengthOfArray);

	cout << "\nArray2 Elements : \n";
	PrintArray(Array2, LengthOfArray);

	SumTowArray(Array1, Array2, SumArray, LengthOfArray);
	cout << "\nSum of array1 and Array2 elements : \n";
	PrintArray(SumArray, LengthOfArray);
	return 0;
}

