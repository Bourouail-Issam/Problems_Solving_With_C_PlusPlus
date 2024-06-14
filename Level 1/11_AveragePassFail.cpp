
#include <iostream>
using namespace std;
enum enPassFail { Pass=1,Fail=2};
void ReadNumber(int& Mark1,int& Mark2,int& Mark3) {

    cout << "Please Enter Number 1 : ";
    cin >> Mark1;
    cout << "Please Enter Number 2 : ";
    cin >> Mark2;
    cout << "Please Enter Number 3 : ";
    cin >> Mark3;
}
int SumOf3Numbers(int Mark1, int Mark2, int Mark3) {
    return Mark1 + Mark2 + Mark3;
}
float Average(int sum) {
    return (float)sum / 3;
}
enPassFail checkAverage(float average) 
{
    if (average >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}
void PrintPassFail(float average) {
    if (checkAverage(average) == enPassFail::Pass)
        cout << "\nPass :" << "Average is " << average << endl;
    else
        cout << "\nFail :" << "Average is " << average << endl;
}
int main()
{
    int Mark1,Mark2,Mark3;
    ReadNumber(Mark1, Mark2, Mark3);
    PrintPassFail(Average(SumOf3Numbers(Mark1, Mark2, Mark3)));
}

