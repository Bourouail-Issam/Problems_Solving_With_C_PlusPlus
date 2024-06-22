#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
char ReadChar() {
	char letter;
	cout << "Please Enter a letter ?\n";
	cin >> letter;
	return letter;
}

char InvertingCharacterLetter(char Letter) {
	return isupper(Letter) ? tolower(Letter) : toupper(Letter) ;
}

int main() {
	char letter = ReadChar();

	cout << "\nafter invertion case: \n";
	letter = InvertingCharacterLetter(letter);
	cout << letter;

}

