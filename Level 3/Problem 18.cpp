#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int randomNumber(int From, int To) {
	int random = rand() % (To - From + 1) + From;
	return random;
}
void FileMatrixArr(int ArrMatrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
		for (int j = 0; j < Cols; j++) 
			ArrMatrix[i][j] = randomNumber(0, 9);
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			printf(" %d   ", ArrMatrix[i][j]);
		cout << endl;
	}
}
bool FindNumber(int Arr[3][3], int Rows, int Cols, int NumberSearchr) {

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Arr[i][j] == NumberSearchr)
				return true;
		}
	}
	return false;
}
void  PrintIntersectedNumber(int Arr_1[3][3], int Arr_2[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++) 
		{
			if (FindNumber(Arr_2, 3, 3, Arr_1[i][j]))
				cout << Arr_1[i][j] << setw(3);
		}
	}
}
int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix_1[3][3], ArrMatrix_2[3][3];

	FileMatrixArr(ArrMatrix_1, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix_1, 3, 3);

	FileMatrixArr(ArrMatrix_2, 3, 3);
	cout << "\nMatrix 2 :\n";
	PrintMatrixArr(ArrMatrix_2, 3, 3);

	cout << "\nIntersted Number Are : \n\n";
	PrintIntersectedNumber(ArrMatrix_1, ArrMatrix_2, 3, 3);

	return 0;
}

