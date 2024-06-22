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
			ArrMatrix[i][j] = randomNumber(1,10);
		}
	}
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			cout << setw(3) << ArrMatrix[i][j] << "    ";
		cout << endl;
	}
}

void Mullp_Two_Arr(int Arr1[3][3], int Arr2[3][3],int result[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			result[i][j] = Arr1[i][j] * Arr2[i][j];
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix_1[3][3], ArrMatrix_2[3][3], MullpArr[3][3];

	FileMatrixArr(ArrMatrix_1, 3, 3);
	FileMatrixArr(ArrMatrix_2, 3, 3);

	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix_1, 3, 3);

	cout << "\nMatrix 2 :\n";
	PrintMatrixArr(ArrMatrix_2, 3, 3);


	Mullp_Two_Arr(ArrMatrix_1, ArrMatrix_2, MullpArr, 3, 3);
	cout << "\nResult :\n";
	PrintMatrixArr(MullpArr, 3, 3);
}

