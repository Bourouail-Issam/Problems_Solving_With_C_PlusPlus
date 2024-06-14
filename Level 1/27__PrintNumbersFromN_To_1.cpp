#include <iostream>
using namespace std;

int ReadNumber() {
    int N = 0;
    cout << "Please Enter Number : ";
    cin >> N;
    return N;
}
void PrintRangeFrom_N_To_1_WithWhileLoop(int N) {
    cout << "Range printed using While Loop\n";
    int counter = N;

    while (counter >= 1)
    {
        cout << counter << endl;
        counter--;
    }
}
void PrintRangeFrom_N_To_1_With_DoWhileLoop(int N) {
    cout << "Range printed using do_While Loop\n";
    int counter = N+1;
    do
    {
        counter--;
        cout << counter << endl;
    } while (counter > 1);

}
void PrintRangeFrom_N_To_1_WithForLoop(int N) {
    cout << "Range printed using For Loop\n";
    for (int i = N; i >= 1; i--) {
        cout << i << endl;
    }
}
int main()
{
    int N = ReadNumber();
    PrintRangeFrom_N_To_1_WithWhileLoop(N);
    PrintRangeFrom_N_To_1_With_DoWhileLoop(N);
    PrintRangeFrom_N_To_1_WithForLoop(N);

    return 0;
}
