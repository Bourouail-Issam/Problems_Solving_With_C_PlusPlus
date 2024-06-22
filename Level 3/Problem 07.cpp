#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void FileMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	int OrderNumber = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			OrderNumber++;
			ArrMatrix[i][j] = OrderNumber;
		}
	}
}
void PrintMatrixArr(int ArrMatrix[3][3], int Rows, int Cols) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++)
			cout << setw(2) << ArrMatrix[i][j] << "    ";
		cout << endl;
	}
}

void PrintTransposedMatrix(int ArrMatrix[3][3], int ArrTransposed[3][3],int Rows, int Cols) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				ArrTransposed[i][j] = ArrMatrix[j][i] ;
		}
}
int main() {
	srand((unsigned)time(NULL));
	int ArrMatrix[3][3], ArrTransposed[3][3];

	FileMatrixArr(ArrMatrix, 3, 3);
	cout << "\n The following is a 3x3 order numbers matrix :\n";
	PrintMatrixArr(ArrMatrix, 3, 3);

	PrintTransposedMatrix(ArrMatrix, ArrTransposed, 3, 3);
	cout << "\n The following is the transposed matrix :\n";
	PrintMatrixArr(ArrTransposed, 3, 3);
}

