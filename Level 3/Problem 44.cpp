#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinAllString(vector<string>& vString, string seperator) {

	string S1 = "";

	for (string& word : vString)
		S1 += word + " ";
	
	return S1.substr(0, S1.length() - seperator.length());
}

string RemoveAllPunctuations(string S1, string delims) {
	string NewString = "";

	for (int i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
			NewString += S1[i];
	}

	return NewString;
}

int main() {

	string S1 = ";;,,''..Welcome to Jordan , Jordan is a nice ,,;;country; it's,  amazing,.....",
		StringToReplace = ",;'";

	cout << "Original String : \n" << S1 << endl;
	cout << "\nReplace with match case :\n";
	cout << RemoveAllPunctuations(S1,"';,") << "\n";

	return 0;
}



