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
char InvertLetterCase(char letter) {
	return isupper(letter) ? tolower(letter) : toupper(letter) ;
}
int countLetter(string Paragraph, char Letter, bool MatchCase = true) {
	int counter = 0;
	for (int i = 0; i < Paragraph.length(); i++)
	{
		if (MatchCase)
		{
			if (Letter == Paragraph[i])
				counter++;
		}
		else 
		{
			if (tolower(Letter) == tolower(Paragraph[i]))
				counter++;
		}
		
	}
	return counter;
}

int main() {
	string Paragraph = ReadString();
	char Letter = ReadChar();

	cout << "\nLetter " << Letter << " count = " << countLetter(Paragraph, Letter);

	cout << "\n\nLetter " << Letter<< " or "<< InvertLetterCase(Letter)
		 << " count = " << countLetter(Paragraph, Letter,false);

	return 0;
}

