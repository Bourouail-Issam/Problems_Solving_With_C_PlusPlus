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
			printf(" %0*d   ", 2, ArrMatrix[i][j]);
		cout << endl;
	}
}

int SumItemMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) 
{
	int sommeItemArr = 0;

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			sommeItemArr += ArrMatrix[i][j];
	}
	return sommeItemArr;
}
int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix[3][3];
	FileMatrixArr(ArrMatrix, 3, 3);

	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	cout << "\nSum of Matrix is : " << SumItemMatrixArr(ArrMatrix, 3, 3) << endl;
}

