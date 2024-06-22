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
				ArrMatrix[i][j] = randomNumber(8, 9);
			else
			    ArrMatrix[i][j] = randomNumber(0,0);
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

bool IsScalarMatrix(int Arr[3][3], int Rows, int Cols) 
{
	int FirstElementInArr = Arr[0][0];
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) 
		{
			if (i == j && Arr[i][j] != FirstElementInArr)
				return false;
			else if (i != j && Arr[i][j] !=0) 
			{
					return false;
			}
		}
	}
	return true;
}
int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][3];

	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\nMatrix 1 :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	if (IsScalarMatrix(ArrMatrix,3,3))
		printf("\nYes : martices is Scalar \n");
	else
		printf("\nNo : martices is Not Scalar \n");

	return 0;
}

