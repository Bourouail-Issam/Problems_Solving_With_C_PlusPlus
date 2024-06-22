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
				ArrMatrix[i][j] = randomNumber(1, 9);
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

short NumberRepeatInMatrix(int Arr[3][3], int Rows, int Cols, int Number) {
	short counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++) 
		{
			if (Number == Arr[i][j])
				counter++;
		}
	}
	return counter;
}
int main() {
	srand((unsigned)time(NULL));

	int ArrMatrix[3][3];
	FileMatrixArr(ArrMatrix, 3, 3);

	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	int number ;
	cout << "Enter Number to count in matrix : ";
	cin >> number;

	cout << "\nNumber " << number << " count in matrix is "
		<< NumberRepeatInMatrix(ArrMatrix,3,3,number) << endl;

	return 0;
}

