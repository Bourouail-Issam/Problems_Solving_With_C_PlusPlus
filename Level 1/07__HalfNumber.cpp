
#include <iostream>
#include <string>
using namespace std;

int ReadNumber() {
    int Number;
    cout << "Please Enter Number integer : ";
    cin >> Number;
    return Number;
}

float changeToHalfNumber(int num) {
    float half = (float)num / 2;
    return half;
}
void PrintHalfNumber(int num) {

    string result = "Half of " + to_string(num) + " is " + to_string(changeToHalfNumber(num));
    
    // autre solution
    //cout << "\nHalf Number " << num << " is " << changeToHalfNumber(num);

    cout << result;
}
int main()
{
    PrintHalfNumber(ReadNumber());
}
