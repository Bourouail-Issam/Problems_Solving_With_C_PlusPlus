
#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& B) {

    cout << "\nProgramme to calculate Rectangle Area \n";
    cout << "\nPlease enter Number of Rectangular With : ";
    cin >> A;
    cout << "\nPlease enter Number of Rectangular length : ";
    cin >> B;
}
float RectangleArea(float A, float B) {
    return A * B;
}
void PrintRectangleArea(float Area) {
    cout << "\nRectangle Area is " << Area << endl;
}
int main()
{
    float A, B;
    ReadNumbers(A, B);
    PrintRectangleArea(RectangleArea(A, B));
}
