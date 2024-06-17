
#include <iostream>
#include <cstdlib>
using namespace std;

enum EnCharType { SmallLetter = 1, CapitalLetter = 2, SpecialC = 3, Digit = 4 };

int Random(int From, int To) {
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
int ReadPositiveNumber(string Msg){
    int number = 0;
    do{
        cout << Msg;
        cin >> number;
    } while (number <= 0);
    return number;
}
string Generat_4_Word(EnCharType TypeChar,short length) {
    string word = "";
    for (int i = 0; i < length; i++)
    {
        word += GetRandomCharacter(TypeChar);
    }
    return word;
}
string GeneratKey(short length) {
    string KeyG = "";
    for (int i = 0; i < length; i++)
    {
        KeyG += Generat_4_Word(EnCharType::CapitalLetter, 4);
        if (i <= length - 2)
            KeyG += '-';
    }
    return KeyG;
}
void GetRandomKeys(int NumberOfKeys) {
    for (int i = 1; i <= NumberOfKeys; i++)
        cout << "Key [" << i << "] : " << GeneratKey(4) << endl;
}
int main() {
    srand((unsigned)time(NULL));
    GetRandomKeys(ReadPositiveNumber("Please Enter Number of keys do you want : "));
}


