
#include <iostream>
using namespace std;

void readNumbers(int& num1, int& num2, int& num3){
    
    cout << "Enter Number 1 : ";
    cin >> num1;
    cout << "Enter Number 2 : ";
    cin >> num2;
    cout << "Enter Number 3 : ";
    cin >> num3;
}

int CalcSumOf3numbers(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}
void PrintSum(int result) {
    cout << "the totale sum is " << result;
}
int main()
{
    int num1, num2, num3;
    readNumbers(num1, num2, num3);
    PrintSum(CalcSumOf3numbers(num1, num2, num3));
    return 0;
}


