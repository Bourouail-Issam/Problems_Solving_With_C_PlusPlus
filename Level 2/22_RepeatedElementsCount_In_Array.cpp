
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

void ReadArray (int  Arr[100], int& Arraylength){
    Arraylength = ReadPositiveNumber("Please Enter Number of Array : ");
    for (int i = 0; i < Arraylength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> Arr[i];
    }
}
void PrintArray(int  Arr[100], int lengthOfArray) {
    cout << "Original Array : ";
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int TimesReapted(int  Arr[100] ,int lengthOfArray, int NumberCheck) {
    int counter = 0;
    for (int i = 0; i < lengthOfArray; i++)
    {
        if (Arr[i] == NumberCheck)
            counter++;
    }
    return counter;
}

int main()
{
    int  Arr[100], Arraylength = 0, CheckNumber = 0;
    ReadArray(Arr, Arraylength);

    CheckNumber = ReadPositiveNumber("Enter the number you want to check: ");
    PrintArray(Arr, Arraylength);
    cout << CheckNumber << " is repeated " << TimesReapted(Arr, Arraylength, CheckNumber) << " times(s) \n";
    return 0;
}

