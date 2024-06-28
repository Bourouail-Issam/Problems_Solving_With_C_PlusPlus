#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*string JoinWords(vector <string>& vString, string sperator) {
	string JoinString;

	for (int i = 0; i < vString.size();i++)
	{
		JoinString += vString[i] + sperator;

		if (i == (vString.size() - 1))
			JoinString += vString[i];

	}
	return JoinString;
}*/

string JoinWords(vector <string>& vString, string seperator) {
	 
	string JoinString;

	for (string& word : vString) {
		JoinString += word + seperator;
	}

	return JoinString.substr(0, JoinString.length()-seperator.length());
}

int main() {
	vector<string> vString{ "Mohammed", "Faid" , "Ali", "Maher"};
	cout << "Vector After Join :\n\n";

	cout << JoinWords(vString, ",") <<"\n\n";

	return 0;
}