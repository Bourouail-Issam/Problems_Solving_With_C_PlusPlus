#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector <string> SplitString(string S1, string delim) {
	vector<string> vString;
	int pos = 0;
	string sWord;

	while ((pos = S1.find(delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);

		if (S1 != "")
			vString.push_back(sWord);

		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
		vString.push_back(S1);

	return vString;
}
string LowerAllString(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string JoinAllString(vector<string>& vString , string seperator) {

	string S1 ="";

	for (string& word : vString) 
		S1 += word + " ";
	
	return S1.substr(0, S1.length() - seperator.length());
}
string ReplaceWordInStringUsingSplit(string S1, string OldName, string NewName, bool MatchCase = true)
{
	vector <string> vString;
	vString = SplitString(S1, " ");

	for (string& word : vString) 
	{
		if (MatchCase) {
			if (word == OldName)
				word = NewName ;
		}
		else 
		{
			if (LowerAllString(word) == LowerAllString(OldName))
				word = NewName;
		}
	}
	return JoinAllString(vString, " ");
}
int main() {
	string S1 = "Welcome to jordan , JORDAN is a nice country", 
		StringToReplace = "jordan",ReplaceTo = "USA";
	cout << "Original String : \n" << S1 <<endl;

	cout << "\nReplace with match case :\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo) << "\n";

	cout << "\nReplace with dont match case :\n";
	cout << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << "\n\n";

	return 0;
}



