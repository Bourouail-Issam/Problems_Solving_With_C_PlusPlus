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
bool FindNumber(int Arr[3][3], int Rows, int Cols, int NumberSearchr) {

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			if (Arr[i][j] == NumberSearchr)
				return true;
		}
	}
	return false;
}
int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix[3][3];
	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	int NumberSearchr;
	cout << "\nPlease Enter the number to look for in Matrix : ";
	cin >> NumberSearchr;

	if (FindNumber(ArrMatrix, 3, 3, NumberSearchr))
		cout << "\nYes: it is there>\n";
	else
		cout << "\nNo: it is not there>\n";

	return 0;
}

