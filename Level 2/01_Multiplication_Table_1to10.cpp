
#include <iostream>
using namespace std;

void Header() {
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    for (int i = 1; i <= 10; i++) {
        cout << "\t " << i;
   }
    cout <<endl
    << "------------------------------------------------------------------------------------\n";
}

string Separator(int Number) {
    if (Number < 10)
        return  "   |   ";
    else
        return "  |   ";
}

void PrintMultiplication_1To_10() {
    Header();
    for (int i = 1; i <= 10; i++) 
    {
        cout << " " << i << Separator(i);
        for (int j = 1; j <= 10; j++)
        {
            cout  << i*j << "\t";
        }
        cout << endl;
    }
}

int main()
{
    PrintMultiplication_1To_10();
}

