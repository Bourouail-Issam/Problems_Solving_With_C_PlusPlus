#include <iostream>
using namespace std;

int ReadNumber() {
    int N = 0;
    cout << "Please Enter Number : ";
    cin >> N;
    return N;
}
void PrintRangeFrom_1_To_N_WithWhileLoop(int N) {

    cout << "Range printed using While Loop\n";
    int counter = 1;
    while (counter <= N)
    {
        cout << counter << endl;
        counter++;
    }
}
void PrintRangeFrom_1_To_N_With_DoWhileLoop(int N) {
    cout << "Range printed using do_While Loop\n";
    int counter = 0;
    do
    {
        counter++;
        cout << counter << endl;
    } while (counter < N);
   
}
void PrintRangeFrom_1_To_N_WithForLoop(int N) {
    cout << "Range printed using For Loop\n";
    for (int i = 1; i <= N; i++) {
        cout << i << endl;
    }
}
int main()
{
    int N = ReadNumber();

    PrintRangeFrom_1_To_N_WithWhileLoop(N);
    PrintRangeFrom_1_To_N_With_DoWhileLoop(N);
    PrintRangeFrom_1_To_N_WithForLoop(N);

    return 0;
}
