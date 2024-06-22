#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int randomNumber(int From, int To) {
	int random = rand() % (To - From + 1) + From;
	return random;
}
void FileMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	int counter = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			counter++;
			ArrMatrix[i][j] = randomNumber(1,10);
		}
	}
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			printf(" %0*d   ", 2, ArrMatrix[i][j]);
		cout << endl;
	}
}

bool CheckArraryAreTypical(int Arr1[3][3], int Arr2[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Arr1[i][j] != Arr2[i][j])
				return false;
		}
	}
	return true;
}
int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix1[3][3], ArrMatrix2[3][3];

	FileMatrixArr(ArrMatrix1, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix1, 3, 3);

	FileMatrixArr(ArrMatrix2, 3, 3);
	cout << "\nMatrix 2 :\n";
	PrintMatrixArr(ArrMatrix2, 3, 3);

	if (CheckArraryAreTypical(ArrMatrix1, ArrMatrix2, 3, 3))
		printf("\nYes : martices are equel \n");
	else
		printf("\nNo : martices are Not equel \n");
}

