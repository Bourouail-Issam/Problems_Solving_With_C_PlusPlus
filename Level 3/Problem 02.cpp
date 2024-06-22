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
int RowSum(int ArrMatrix[3][3], int Rows, int Cols) {
	int sum = 0;
	for (int j = 0; j < Cols; j++) {
		sum += ArrMatrix[Rows][j];
	}
	return sum;
}
void PrintEachRowSum(int ArrMatrix[3][3], int Rows, int Cols) {
	cout << "\nThe following are the sum of each row in the matrix : \n";
	for (int i = 0; i < Rows; i++) {
		cout << " Row " << i + 1 << " Sum = " << RowSum(ArrMatrix, i, Cols) <<endl;
	}
}
int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][3];
	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\nThe following is a 3x3 random matrix : \n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	PrintEachRowSum(ArrMatrix,3,3);
	system("pause>0");
	return 0;
}

