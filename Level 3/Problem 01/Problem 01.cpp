
#include <iostream>
#include "MyNumberFun.h"
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To) {
	int RandomNum = (rand() % (To - From + 1)) + From;
	return RandomNum;
}
void FileMatrixArr(int MatrixArr[3][3], int NumberRow, int NumberColumn) {
	for (int i = 0; i < NumberRow; i++) {
		for (int j = 0; j < NumberColumn; j++) {
			MatrixArr[i][j] = MyNumberFun::RandomNumber(1, 100);
		}
	}
}

void PrintMatrixArr(int MatrixArr[3][3], int NumberRow, int NumberColumn) {
	for (int i = 0; i < NumberRow; i++) {
		for (int j = 0; j < NumberColumn; j++) {
			cout << setw(3) << MatrixArr[i][j] << "    ";
		}
		cout << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int MatrixArr[3][3];
	FileMatrixArr(MatrixArr, 3, 3);

	cout << "\n The following is a 3x3 random matrix :\n";
	PrintMatrixArr(MatrixArr, 3, 3);
	return 0;
}
