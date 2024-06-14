#include <iostream>
using namespace std;

int ReadAndPositiveNumber(string Message) {
    int N = 0;

    do {
        cout << Message;
        cin >> N;
    } while (N <0);

    return N;
}
void Factorial_Of_N_WithWhileLoop(int N) {
   
    int counter = N, factorial =N;

    while (counter > 1)
    {
        counter--;
        factorial *= counter;
    }

    cout << factorial << endl;
}
void Factorial_Of_N_With_DoWhileLoop(int N) {
    int counter = 0, factorial = 1;

    do {
        counter++;
        factorial *= counter;
    } while (counter <N);

    cout << factorial << endl;

}
void Factorial_Of_N_WithForLoop(int N) {

    int factorial = 1;

    for (int counter = 1; counter <= N; counter++)
        factorial *= counter;

    cout << factorial << endl;
}

int main()
{
    int N = ReadAndPositiveNumber("Please Enter Positive Number : ");

    Factorial_Of_N_WithWhileLoop(N);
    Factorial_Of_N_With_DoWhileLoop(N);
    Factorial_Of_N_WithForLoop(N);

    return 0;
}
