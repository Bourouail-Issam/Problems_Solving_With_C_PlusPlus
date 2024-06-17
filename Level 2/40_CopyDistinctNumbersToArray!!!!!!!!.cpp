#include <iostream>
#include <cmath>
using namespace std;

void FillArray (int Arr[100],int& ArrLength) {
	ArrLength = 10;
	Arr[0] = 10; Arr[1] = 10; Arr[2] = 10; Arr[3] = 50; Arr[4] = 50; 
	Arr[5] = 70; Arr[6] = 70; Arr[7] = 70; Arr[8] = 70; Arr[9] = 90;
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl << "\n";
}
short FindNumberPositionInArray(int Array[100], int ArrLength, int SearchNumber) {
	for (int i = 0; i < ArrLength; i++) {
		if (SearchNumber == Array[i])
			return i;//return index
	}
	//if you reached here, this means the number is not found
	return -1;
}
bool IsNumberInArray(int Array[100], int ArrLength, int SearchNumber) {
	return FindNumberPositionInArray(Array, ArrLength, SearchNumber) != -1;
}
void AddArrayElement(int Number, int Arr[100], int& ArrLength) {
	Arr[ArrLength] = Number;
	ArrLength++;
}
void CopyDistinctNumbersToArray(int ArrSource[100], int ArrDestination[100], int SourceLength, int& DestinationLength) {
	for (int i = 0; i < SourceLength; i++){
		if (!IsNumberInArray(ArrDestination, DestinationLength, ArrSource[i])) {
			AddArrayElement(ArrSource[i], ArrDestination, DestinationLength);
		}
	}
}
int main() {
	int ArrSource[100] , SourceLength = 0 , ArrDestination[100], DestinationLength = 0;
	FillArray(ArrSource, SourceLength);

	cout << "\nArray 1 Elements: ";
	PrintArray(ArrSource, SourceLength);

	CopyDistinctNumbersToArray(ArrSource, ArrDestination , SourceLength , DestinationLength);

	cout << "\nArray 2 Elements: ";
	PrintArray(ArrDestination, DestinationLength);
	return 0;
}
