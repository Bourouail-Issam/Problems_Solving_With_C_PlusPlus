#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void PrintMatrixArr(int ArrMatrix[3][5], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			printf(" %d   ", ArrMatrix[i][j]);
		cout << endl;
	}
}
bool IsPalindromMatrix(int Arr[3][5], int Rows, int Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols/2; j++)
		{
			if (Arr[i][j] != Arr[i][Cols - 1 - j])
				return false;
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][5] = { {1,1,2,1,1},{5,5,5,5,5},{7,7,4,7,7} };

	
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 5);
	
	if (IsPalindromMatrix(ArrMatrix,3,5))
		cout << "\nYes : Matrix is palindrom \n";
	else
		cout << "\nNo : Matrix is Not palindrom \n";
	
	return 0;
}

