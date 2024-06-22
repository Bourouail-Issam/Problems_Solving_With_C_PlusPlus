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
void PrintFirstLetterOfEachWord(string paragraph) {
	bool isFirstLetter = true;

	for (int i = 0; i < paragraph.length(); i++)
	{
		if (paragraph[i] != ' ' && isFirstLetter)
			cout << paragraph[i] << endl;
		isFirstLetter = paragraph[i] == ' ' ? true : false;
	}
}

int main() {
	string paragraph = ReadString();
	PrintFirstLetterOfEachWord(paragraph);

	return 0;
}

