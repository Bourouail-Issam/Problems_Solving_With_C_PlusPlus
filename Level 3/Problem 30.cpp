#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string pharagraph;
	cout << "\nPlease Enter Your string : ";
	getline(cin, pharagraph);
	return pharagraph;
}
char ReadChar() {
	char letter;
	cout << "\nPlease Enter a Character : ";
	cin >> letter;
	return letter;
}
int CountSmallLetter(string Paragraph, char Letter) {
	int counter = 0;
	for (int i = 0; i < Paragraph.length(); i++) {
		if (Paragraph[i] == Letter)
			counter++;
	}
	return counter;
}

int main() {
	string Paragraph = ReadString();
	char Letter = ReadChar();
	cout << "\nLetter " << Letter << " count = " << CountSmallLetter(Paragraph, Letter);
}

