#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int RandomNumber(int From, int To) {
	int random = rand() % (To - From + 1) + From;
	return random;
}
void FileMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			ArrMatrix[i][j] = RandomNumber(1, 100);
	}
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			cout << setw(3) << ArrMatrix[i][j] << "    ";
		cout << endl;
	}
}
int ColSum(int ArrMatrix[3][3], int Rows, int Cols) {
	int sum = 0;
	for (int j = 0; j < Rows; j++) {
		sum += ArrMatrix[j][Cols];
	}
	return sum;
}
void filArrWithSumCols(int ArrSumCols[3], int ArrMatrix[3][3], int Rows, int Cols) {

	for (int i = 0; i < Rows; i++) {
		ArrSumCols[i] = ColSum(ArrMatrix, Rows, i);
	}
}
void PrintColumsSumArray(int ArrSumCols[3], int length) {
	cout << "\nThe following are the sum of each col in the matrix : \n";
	for (int i = 0; i < length; i++) {
		cout << " Col " << i + 1 << " Sum = " << ArrSumCols[i] << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][3];
	int ArrSumCols[3];

	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\nThe following is a 3x3 random matrix : \n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	filArrWithSumCols(ArrSumCols, ArrMatrix, 3, 3);
	PrintColumsSumArray(ArrSumCols, 3);

	system("pause>0");
}

