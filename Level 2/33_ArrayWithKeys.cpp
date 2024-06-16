#include <iostream>
#include <cmath>
using namespace std;
enum EnCharType { SmallLetter = 1, CapitalLetter = 2, SpecialC = 3, Digit = 4 };
int ReadPositiveNumber(string Msg) {
	int Number = 0;
	do {
		cout << Msg;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int RandomNummber(int From, int To) {
	int Random = rand() % (To - From + 1) + From;
	return Random;
}
char GetRandomCharacter(EnCharType Type_Key) {
	switch (Type_Key){
	case EnCharType::SmallLetter:
		return char(RandomNummber(97, 122));
	case EnCharType::CapitalLetter:
		return char(RandomNummber(65, 90));
	case EnCharType::SpecialC:
		return char(RandomNummber(33, 47));
	case EnCharType::Digit:
		return char(RandomNummber(48, 57));
	}
}
string Generat_4_Words(EnCharType Type_Key , int length) {
	string Words = "";
	for (int i = 0; i < length; i++){
		Words += GetRandomCharacter(Type_Key);
	}
	return Words;
}
string GeneratKey(int length) {
	string G_Key = "";
	for (int i = 0; i < length; i++){
		G_Key += Generat_4_Words(EnCharType::CapitalLetter,4);
		if (i <= length - 2)
			G_Key += "-";
	}
	return G_Key;
}
void FillArrayWithKeys(string Array[100], int& LengthOfArray) {
	LengthOfArray = ReadPositiveNumber("Please Enter Number Of Array : ");
	for (int i = 0; i < LengthOfArray; i++)
		Array[i] = GeneratKey(4);
}
void PrintArray(string Array[100], int LengthOfArray) {
	for (int i = 0; i < LengthOfArray; i++)
		cout << "Array[" << i+1<<"] : " << Array[i] << "\n";
	cout << endl;
}
int main() {
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
	string Array[100];
	int LengthOfArray = 0;
	FillArrayWithKeys(Array, LengthOfArray);
	cout << "\nArray Elements: \n\n";
	PrintArray(Array, LengthOfArray);
	return 0;
}
