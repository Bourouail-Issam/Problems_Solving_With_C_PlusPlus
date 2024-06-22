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
				ArrMatrix[i][j] =0;
			else
				ArrMatrix[i][j] = randomNumber(0, 2);
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
short couterNumberInMatrix(int Arr[3][3],int Rows ,int Cols) {
	short counter = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Arr[i][j] == 0)
				counter++;
		}
	}
	return counter;
}
bool IsSparceMatrix(int Arr[3][3], int Rows, int Cols) {
	int SizeOfMatrix = Rows * Cols;
	return (couterNumberInMatrix(Arr, Rows, Cols) >= (SizeOfMatrix / 2));
}

int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix[3][3];
	FileMatrixArr(ArrMatrix, 3, 3);

	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	if (IsSparceMatrix(ArrMatrix, 3, 3))
		cout << "\nYes: It is Sparse\n";
	else
		cout << "\nNo: It is Not Sparse\n";

	return 0;
}

