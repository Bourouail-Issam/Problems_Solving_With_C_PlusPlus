#include <iostream>
#include <string>
#include <vector>
using namespace std;


string ReadString() {
	string letter;
	cout << "\nPlease Enter a Character : ";
	getline(cin, letter);
	return letter;
}
vector <string> splitString(string S1, string Delim ) {

	vector <string> vString;
	string sWord;
	int pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord !="") 
			vString.push_back(sWord);
		
		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "") 
		vString.push_back(S1);

	return vString;
}


int main() {
	vector <string> vString;

	vString = splitString(ReadString(), " ");
	cout << "Tokens = " << vString.size() << endl;

	for (string& word : vString) {
		cout << word << endl;
	}
}