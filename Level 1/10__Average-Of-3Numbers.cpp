// soulution with simple variable
// 
//#include <iostream>
//using namespace std;
//void readNumbers(int& num1, int& num2, int& num3) {
//
//    cout << "Enter Number 1 : ";
//    cin >> num1;
//    cout << "Enter Number 2 : ";
//    cin >> num2;
//    cout << "Enter Number 3 : ";
//    cin >> num3;
//}
//
//int SumOf3numbers(int num1, int num2, int num3) {
//    return num1 + num2 + num3;
//}
//float AverageOf3Numbers ( int num1, int num2, int num3) {
//    return (float)SumOf3numbers(num1, num2, num3) / 3;
//}
//void PrintSum(float Average) {
//    cout << "the Average is " << Average;
//}
//int main()
//{
//    int num1, num2, num3;
//    readNumbers(num1, num2, num3);
//    readNumbers(num1, num2, num3);
//    PrintSum(AverageOf3Numbers(num1, num2, num3));
//    return 0;
//}
//
//

// Autre soulution with array
#include <iostream>
using namespace std;
void readNumbers(int num[3]) {
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Number " << i + 1 << " : ";
        cin >> num[i];
    }
}

int SumOf3numbers(int num[3]) {
    int result = 0;
    for (int i = 0; i < 3; i++) {
        result += num[i];
    }
    return result;
}

float AverageOf3Numbers(int num[3]) {
    return (float)SumOf3numbers(num) / 3;
}

void PrintAvg(float Average) {
    cout << "the Average is " << Average << endl;
}

int main()
{
    int num[3];
    readNumbers(num);
    PrintAvg(AverageOf3Numbers(num));
    return 0;
}

