#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


string ReadString() {
	string S1;
	cout << "Please Enter a letter ?\n";
	getline(cin, S1);
	return S1;
}

char InvertingCharacterLetter(char Letter) {
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

string InvertAllStringLettersCase(string S1) {

	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertingCharacterLetter(S1[i]);
	}
	return S1;
}

int main() {
	string S1 = ReadString();

	cout << "\nafter invertion case: \n";
	S1 = InvertingCharacterLetter(stringPara);
	cout << S1;

	system("pause>0");
	return 0;
}

