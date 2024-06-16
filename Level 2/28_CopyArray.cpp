
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
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void CopyOriginalArr(int  OriginalArr[100], int lengthOfArra ,int coppArray[100]) {
    for (int i = 0; i < lengthOfArra; i++)
    {
        coppArray[i] = OriginalArr[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int  OriginalArr[100], CopyArray[100], Arraylength = 0;

    FillArray(OriginalArr, Arraylength);
    CopyOriginalArr(OriginalArr, Arraylength, CopyArray);

    cout << "Array 1 elements : \n";
    PrintArray(OriginalArr, Arraylength);

    cout << "Array 2 elements : \n";
    PrintArray(CopyArray, Arraylength);

    return 0;
}

