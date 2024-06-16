
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Msg) {
    int number = 0;
    do {
        cout << Msg;
        cin >> number;
    } while (number <= 0);
    return number;
}
int Random(int From, int To) {
    int Random = rand() % (To - From + 1) + From;
    return Random;
}
void FillArray(int  Arr[100], int& Arraylength) {
    Arraylength = ReadPositiveNumber("Please Enter Number of Array : ");
    for (int i = 0; i < Arraylength; i++)
    {
        Arr[i] = Random(1, 100);
    }
}
void PrintArray(int  Arr[100], int lengthOfArray) {
    cout << "Array Elements : ";
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}
void FindMaxNumberOfArray(int  Arr[100], int Arraylength) {
    int MaxNumber = 0;
    for (int i = 0; i < Arraylength; i++)
    {
        if (MaxNumber < Arr[i])
            MaxNumber = Arr[i];
    }
    cout << "\nMax Number is " << MaxNumber << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int  Arr[100], Arraylength = 0;
    FillArray(Arr, Arraylength);
    PrintArray(Arr, Arraylength);
    FindMaxNumberOfArray(Arr, Arraylength);
    return 0;
}
