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

int countEachWordString(string paragraph) {

	int counter = 0;
	string delim = " ";
	short position = 0;
	string sWord;

	while ((position = paragraph.find(delim)) != std::string::npos) 
	{
		sWord = paragraph.substr(0, position);
		if (sWord != "")
			counter++;

		paragraph.erase(0, position + delim.length());
	}

	if (paragraph != "")
		counter++;

	return counter;
}

int main() {

	cout << "\n\nThe number of words in your string is : "
		 << countEachWordString(ReadString()) << endl;

	return 0;
}