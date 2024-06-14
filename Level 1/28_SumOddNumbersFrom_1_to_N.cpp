#include <iostream>
using namespace std;
enum enOddEvenNumber {Odd = 1, Even = 2};
int ReadNumber() {
    int N = 0;
    cout << "Please Enter Number : ";
    cin >> N;
    return N;
}
enOddEvenNumber checkNumber_Odd_Even(int N) {
    if (N % 2 == 0) 
    {
        return enOddEvenNumber::Even;
    }
    else 
    {
       return enOddEvenNumber::Odd;
    }
}
void SumOddNumbersFrom_1_To_N_WithWhileLoop(int N) {

    cout << "Sum Odd using While Loop\n";
    int counter = 1;
    int sum = 0;

    while (counter <= N) {
        if (checkNumber_Odd_Even(counter) == enOddEvenNumber::Odd) {
            sum += counter;
        }
        counter++;
    }
    cout << sum << endl;
}
void SumOddNumbersFrom_1_To_N_With_DoWhileLoop(int N) {
    cout << "Sum Odd using do_While Loop\n";
    int counter = 0;
    int sum = 0;

    do {
        counter++;
        if (checkNumber_Odd_Even(counter) == enOddEvenNumber::Odd) {
            sum += counter;
        }
    } while (counter < N);
    cout << sum << endl;
}
void SumOddNumbersFrom_1_To_N_WithForLoop(int N) {
    cout << "Sum Odd using For Loop\n";
    int sum = 0;

    for (int i = 1; i <= N; i++) {
        if (checkNumber_Odd_Even(i) == enOddEvenNumber::Odd) {
            sum += i;
        }
    }
    cout << sum << endl;
}
int main()
{
    int N = ReadNumber();
    SumOddNumbersFrom_1_To_N_WithWhileLoop(N);
    SumOddNumbersFrom_1_To_N_With_DoWhileLoop(N);
    SumOddNumbersFrom_1_To_N_WithForLoop(N);

    return 0;
}
