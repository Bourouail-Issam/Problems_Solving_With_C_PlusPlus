#include <iostream>
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
short FindPositionInArray(int Array[100], int ArrLength, int SearchNumber) {
	for (int i = 0; i < ArrLength; i++) {
		if (SearchNumber == Array[i])
			return 1;
	}
	return -1;
}
bool IsNumberInArray(int Array[100], int ArrLength, int SearchNumber) {
	return FindPositionInArray(Array, ArrLength, SearchNumber) != -1;
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl << endl;
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	int Array[100], ArrLength = 0;
	FillArrayWithRandomNumber(Array, ArrLength);

	cout << "\nArray 1 Elements: \n";
	PrintArray(Array, ArrLength);

	int SearchNumber = ReadPositiveNumber("Please Enter a Number to search for : ");
	cout <<endl << "Number you are looking for is : " << SearchNumber << endl;

	if (IsNumberInArray(Array, ArrLength, SearchNumber))
		cout << "Yes, The Number is found :-)" << endl;
	else
		cout << "No, The Number is Not found  :-( " << endl;

	return 0;
}
