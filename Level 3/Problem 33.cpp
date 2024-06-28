#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


string ReadString() {
	string letter;
	cout << "\nPlease Enter a Character : ";
	getline(cin, letter) ;
	return letter;
}

bool isVowelCharacter(char ch1) {
	ch1 = tolower(ch1);
	return((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}
int countNumberVowels(string paragraph) {
	int counter = 0;
	for (int i = 0; i < paragraph.length(); i++) {
		if (isVowelCharacter(paragraph[i]))
			counter++;
	}
	return counter;
}
int main() {

	string paragraph = ReadString();
	cout << "\nNumeber of vowels is : " << countNumberVowels(paragraph)
		<< endl;
}

