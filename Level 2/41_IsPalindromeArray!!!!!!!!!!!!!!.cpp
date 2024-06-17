#include <iostream>
#include <cmath>
using namespace std;

void FillArray(int Arr[100], int& ArrLength) {
	ArrLength = 6;
	Arr[0] = 10; Arr[1] = 20; Arr[2] = 30; Arr[3] = 30; Arr[4] = 20; Arr[5] = 10;
}
void PrintArray(int Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << Array[i] << " ";
	cout << endl << "\n";
}
bool IsPalindromeArray(int ArrSource[100], int SourceLength ){
	for (int i = 0; i < SourceLength; i++) {
		if (ArrSource[i] != ArrSource[SourceLength -1 -i])
			return false;
	}
	return true;
}
int main() {
	int ArrSource[100], SourceLength = 0;
	FillArray(ArrSource, SourceLength);

	cout << "\nArray 1 Elements: ";
	PrintArray(ArrSource, SourceLength);

	if (IsPalindromeArray(ArrSource, SourceLength))
		cout << "Yes Array is Palindrome\n";
	else
		cout << "No Array is Not Palindrome\n";
	return 0;
}
