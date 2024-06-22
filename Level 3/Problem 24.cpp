#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string paragraph;
	cout << "Please Enter Your String ?\n";
	getline(cin, paragraph);
	return paragraph;
}
char ChangeToUpperCase(char Letter) {
	if ((int)Letter >= 97 )
		return char((int)Letter - 32);
	return char(Letter);
}
void UpperFirstLetterOfEachWord(string& paragraph) {
	bool isFirstLetter = true;
	for (int i = 0; i < paragraph.length(); i++)
	{
		if (paragraph[i] != ' ' && isFirstLetter)
		paragraph[i] = ChangeToUpperCase(paragraph[i]);
		//paragraph[i] = toupper(paragraph[i]);
		isFirstLetter = paragraph[i] == ' ' ? true : false;
	}
}

int main() {
	string paragraph = ReadString();

	UpperFirstLetterOfEachWord(paragraph);
	cout << "\nstring after conversion :\n" << paragraph << endl;

	return 0;
}

