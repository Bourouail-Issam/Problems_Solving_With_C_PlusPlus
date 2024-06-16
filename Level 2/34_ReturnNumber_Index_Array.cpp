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
void FillArrayWithRandomNumber_1toN(int Array[100], int& LengthOfArray) {
	LengthOfArray = ReadPositiveNumber("Please Enter Number Of Array : ");
	for (int i = 0; i < LengthOfArray; i++)
		Array[i] = RandomNummber(1,100);
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl;
}
int SearchNumberIn_Array(int Array[100], int ArrLength, int& SearchNumber) {
	SearchNumber = ReadPositiveNumber("Please Enter a Number to search for : ");
	for (int i = 0; i < ArrLength; i++) {
		if (SearchNumber == Array[i])
			return i;
	}
	return -1;
}
void PrintResultSearching(int resultSearching) {
	if(resultSearching == -1)
		cout << "The Number found at position : "<< "-(" << endl;
	if (resultSearching != -1) {
		cout << "The Number found at position :" << resultSearching << endl;
		cout << "The Number found its order :" << resultSearching + 1 << endl;
	}
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	int Array[100], LengthOfArray = 0 , SearchNumber = 0
		;
	FillArrayWithRandomNumber_1toN(Array, LengthOfArray );
	cout << "\nArray 1 Elements: \n\n";
	PrintArray(Array, LengthOfArray);

	int resultSearching = SearchNumberIn_Array(Array, LengthOfArray, SearchNumber);
	cout << "Number you are looking for is : " << SearchNumber << endl;
	PrintResultSearching(resultSearching);
	return 0;
}
