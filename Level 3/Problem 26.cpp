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
	if ((int)Letter >= 97)
		return char((int)Letter - 32);
	return char(Letter);
}
char ChangeToLowerCase(char Letter) {
	if ((int)Letter <= 90)
		return char((int)Letter + 32);
	return char(Letter);
}
void LowerCaseLetterOfEachWord(string& paragraph) {
	for (int i = 0; i < paragraph.length(); i++) {
		if (paragraph[i] != ' ')
		{
			paragraph[i] = ChangeToLowerCase(paragraph[i]);
			//paragraph[i] = tolower(paragraph[i]);
		}
	}
}
void UpperCaseLetterOfEachWord(string& paragraph) {
	for (int i = 0; i < paragraph.length(); i++) {
		if (paragraph[i] != ' ')
			//paragraph[i] = ChangeToUpperCase(paragraph[i]);
			paragraph[i] = toupper(paragraph[i]);
	}
}
int main() {
	string paragraph = ReadString();

	cout << "\nString After Upper : \n";
	UpperCaseLetterOfEachWord(paragraph);
	cout << paragraph << endl;

	cout << "\nString After Lower : \n";
	LowerCaseLetterOfEachWord(paragraph);
	cout << paragraph << endl;

	return 0;
}

