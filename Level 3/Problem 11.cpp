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
			ArrMatrix[i][j] = counter;
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
int SunOfMatrix(int Arr[3][3], int Rows, int Cols) {
	int sum = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			sum += Arr[i][j];
		}
	}
	return sum;
}
bool CheckSumArrEqual(int Arr1[3][3], int Arr2[3][3], int Rows, int Cols){
	return (SunOfMatrix(Arr1,Rows,Cols) == SunOfMatrix(Arr2, Rows, Cols));
}
int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix1[3][3] , ArrMatrix2[3][3];

	FileMatrixArr(ArrMatrix1, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix1, 3, 3);

	FileMatrixArr(ArrMatrix2, 3, 3);
	cout << "\nMatrix 2 :\n";
	PrintMatrixArr(ArrMatrix2, 3, 3);

	CheckSumArrEqual(ArrMatrix1, ArrMatrix2, 3, 3) ? printf("\nYes : martices are equel \n") : printf("\nNo : martices are Not equel \n");
	return 0;
}

