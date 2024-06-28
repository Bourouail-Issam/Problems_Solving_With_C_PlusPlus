#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


string ReadString() {
	string letter;
	cout << "\nPlease Enter a Character : ";
	getline(cin, letter);
	return letter;
}


void PrintEachWordString(string paragraph) {
	string delim = " ";
	cout << "\n\nYour String Words are  : \n\n";
	short position = 0;
	string sWord;

	while ((position = paragraph.find(delim)) != std::string::npos)
	{
		sWord = paragraph.substr(0, position);

		if (sWord != "")
			cout << sWord << endl;

		paragraph.erase(0, position + delim.length());
	}

	if (paragraph != "")
		cout << paragraph << endl;

}
int main() {

	PrintEachWordString(ReadString());
	cout << endl;

	return 0;
}