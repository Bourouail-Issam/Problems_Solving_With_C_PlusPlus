
#include <iostream>
#include <string>
using namespace std;

float ReadNumber(string Message) {
    float Number;
    cout << Message << " : ";
    cin >> Number;
    return Number;
};
float SumNumbers() {
    int counter = 1;
    float  total = 0, Number = 0;
    do {
        float Number = ReadNumber("Please Enter Number " + to_string(counter));
        if (Number == -99) {
            break;
        }
        total += Number;
        counter++;
    } while (Number != -99);
    return total;

}
void PrintResultCalc() {
    cout << "the result is " << SumNumbers() << endl;
}
int main()
{
    PrintResultCalc();
}
