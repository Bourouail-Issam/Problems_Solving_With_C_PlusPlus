
#include <iostream>
#include <string>
using namespace std; 

enum enOperatore{Add = '+', Subtract = '-', Multiply = '*', Divide = '/'};


float ReadNumber(string Message) {
    float Number;
    cout << Message;
    cin >> Number;
    return Number;
};

enOperatore ReadOperation() {
    char Op;
    do {
        cout << "Please Enter Operation (+,-,*,/) : ";
        cin >> Op;
        
    } while (Op != '+' && Op != '-'&& Op != '*' && Op != '/');
    return (enOperatore)Op;
}

float  Calc_TowNumbers(enOperatore OpType, float Nb1 , float Nb2) {
    switch (OpType)
    {
    case enOperatore::Add:
        return Nb1 + Nb2;
    case enOperatore::Subtract:
        return Nb1 - Nb2;
    case enOperatore::Multiply:
        return Nb1 * Nb2;
    case enOperatore::Divide:
        return Nb1 / Nb2;
    default:
        break;
    }
}
void PrintResultCalc (float result){
    cout << "the result is " << result << endl;
}
int main()
{
    float Nb1 = ReadNumber("Please Enter Number 1 : ");
    float Nb2 = ReadNumber("Please Enter Number 2 : ");

    enOperatore OpType  = ReadOperation();
    PrintResultCalc(Calc_TowNumbers(OpType, Nb1, Nb2));

    return 0;
}
