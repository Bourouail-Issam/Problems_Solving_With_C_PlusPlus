#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int randomNumber(int From, int To) {
	int random = rand() % (To - From + 1) + From;
	return random;
}
void FileMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (i == j)
				ArrMatrix[i][j] = randomNumber(0, 9);
			else
				ArrMatrix[i][j] = randomNumber(0, 9);
		}
	}
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			printf(" %d   ", ArrMatrix[i][j]);
		cout << endl;
	}
}
int BigNumberInMatrix(int Arr[3][3], int Rows, int Cols) {
	int BigNumber = Arr[0][0];
	for (int i = 0; i < Rows; i++) 
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Arr[i][j] > BigNumber)
				BigNumber = Arr[i][j];
		}
	}
	return BigNumber;
}
int MinNumberInMatrix(int Arr[3][3], int Rows, int Cols) {
	int MinNumber = Arr[0][0];
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Arr[i][j] < MinNumber)
				MinNumber = Arr[i][j];
		}
	}
	return MinNumber;
}
int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][3];

	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	cout << "\nMinimun Number is  : " << MinNumberInMatrix(ArrMatrix, 3, 3);
	cout << "\nMax Number is  : " << BigNumberInMatrix(ArrMatrix, 3, 3) << endl;

	return 0;
}

