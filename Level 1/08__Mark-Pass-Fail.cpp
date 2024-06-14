
#include <iostream>
using namespace std;

enum enMarknumber { Pass = 1 , Fail = 2 };

int readMark() {

    int MarkNumber;
    cout << "Please enter Mark Number : ";
    cin >> MarkNumber;

    return MarkNumber;
}
enMarknumber checkMark(int numMark) 
{
    if (numMark >= 50)
        return enMarknumber::Pass;
    else
        return enMarknumber::Fail;
}
void printMark(int numMark) {

    if(checkMark(numMark) == enMarknumber::Pass)
        cout << "You Pass\n";
    else
        cout << "You Fail\n";
}
int main()
{
    printMark(readMark());
}


