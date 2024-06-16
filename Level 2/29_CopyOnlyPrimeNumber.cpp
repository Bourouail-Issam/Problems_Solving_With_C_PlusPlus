
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
int ReadPositiveNumber(string Msg){
	int Number = 0;
	do {
		cout << Msg;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int RandomNummber(int From , int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
void FillArray(int Array[100], int &LengthOfArray) {
	LengthOfArray = ReadPositiveNumber("Please Enter Number Of Array : ");
	for (int i = 0; i < LengthOfArray ; i++)
	{
		Array[i] = RandomNummber(1, 100);
	}
}
void  CopyArrayOnlyPrimeNumber(int OrigneArray[100], int CopyArray[100], int LengthOfArray , int& LengthOfCopyArray) {
	int counter = 0;
	for (int i = 0; i < LengthOfArray; i++)
	{
		if (PrimeNumber(OrigneArray[i]) == enPrime_NotPrime::Prime) {
			CopyArray[counter] = OrigneArray[i];
			counter++;
		}
	}
	LengthOfCopyArray = --counter;
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	int Array1[100], LengthOfArray1 = 0;
	FillArray(Array1, LengthOfArray1);
	cout << "\nPrime Numbers in Array1 : \n";
	PrintArray(Array1, LengthOfArray1);
	int Array2[100], lengthOArray2 = 0;
	CopyArrayOnlyPrimeNumber(Array1, Array2, LengthOfArray1 , lengthOArray2);
	cout << "\nPrime Numbers in Array2 : \n";
	PrintArray(Array2, lengthOArray2);
	return 0;
}

