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
		for (int j = 0; j < Cols; j++)
			ArrMatrix[i][j] = randomNumber(1, 10);
	}
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			printf(" %0*d   ",2, ArrMatrix[i][j]);
		cout << endl;
	}
}
void MiddlRow(int ArrMatrix[3][3], int Rows, int Cols) {

	cout << "\nMiddel Row of Matrix1 is : \n";
	int middelRow = Rows/2;

	for (int i = middelRow; i <= middelRow; i++) {
		for (int j = 0; j < Cols; j++) {
			printf(" %0*d   ", 2, ArrMatrix[i][j]);
		}
	}
}
void MiddlCol(int ArrMatrix[3][3], int Rows, int Cols) {

	cout << "\nMiddel col of Matrix1 is : \n";
	int middelCol = Cols / 2;

	for (int i = 0; i < Cols; i++) {
		for (int j = middelCol; j <= middelCol; j++) 
			printf(" %0*d   ", 2, ArrMatrix[i][j]);
	}
}
int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][3];

	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);
		 
	MiddlRow(ArrMatrix, 3, 3);
	MiddlCol(ArrMatrix,3,3);

	return 0;
}

