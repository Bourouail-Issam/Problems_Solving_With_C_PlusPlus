
#include <iostream>
#include <cstdlib>
using namespace std;


enum EnCharType { SmallLetter = 1, CapitalLetter = 2, SpecialC = 3, Digit = 4};

int Random(int From , int To){
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

char GetRandomCharacter(EnCharType charType) {

    switch (charType)
    {
    case EnCharType::SmallLetter:
        return  char(Random(97, 122));
    case EnCharType::CapitalLetter:
        return  char(Random(65, 90));
    case EnCharType::SpecialC:
        return  char(Random(33, 47));
    case EnCharType::Digit:
        return  char(Random(48, 57));
    }
}
int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(EnCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(EnCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(EnCharType::SpecialC) << endl;
    cout << GetRandomCharacter(EnCharType::Digit) << endl;
}


