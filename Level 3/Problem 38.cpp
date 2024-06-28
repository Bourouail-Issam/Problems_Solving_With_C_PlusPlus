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
string TrimLeft (string S1){
	
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ')
			return S1.substr(i, S1.length());
	}
	return "";
}
string TrimRigth(string S1) {

	for (short i = S1.length()-1; i >= 0; i--) {
		if (S1[i] != ' ')
			return S1.substr(0, i+1);
	}
	return "";
}
string Tirm(string S1) {
	return TrimRigth(TrimLeft(S1));
}

int main() {
	string Paragraph = "       Hello world     ";

	cout << "\nTirmLeft  = " << TrimLeft(Paragraph) << "\n";
	cout << "\nTirmRigth = " << TrimRigth(Paragraph) <<"\n";
	cout << "\nTirm      = " << Tirm(Paragraph) <<"\n";

	return 0;
}