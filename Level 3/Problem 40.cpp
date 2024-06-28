#include <iostream>
#include <string>
#include <vector>
using namespace std;


string JoinWords(vector <string>& vString, string seperator) {

	string JoinString;

	for (string& word : vString) {
		JoinString += word + seperator;
	}

	return JoinString.substr(0, JoinString.length()-seperator.length());
}
string JoinWords(string Arr[4], int lengthArr, string seperator) {

	string JoinString;

	for (short i = 0; i < lengthArr; i++) {
		JoinString += Arr[i] + seperator;
	}

	return JoinString.substr(0, JoinString.length() - seperator.length());
}

int main() {

	string ArrJoin[4] = { "Issam", "Hassan" , "Amine", "Shaimaa" };
	cout << "String After Join :\n\n";
	cout << JoinWords(ArrJoin, 4, ",") << "\n\n";

	vector<string> vString{ "Mohammed", "Faid" , "Ali", "Maher"};
	cout << "Vector After Join :\n\n";
	cout << JoinWords(vString, ",") <<"\n\n";

	return 0;
}



