#include <iostream>
#include <string>
#include <vector>
using namespace std;



string ReplaceWordInStringUsingBuiltInFunction(string S1, string OldName, string NewName) {

	int pos = S1.find(OldName);

	while (pos != std::string::npos) {

		S1 = S1.replace(pos, OldName.length(), NewName);
		pos = S1.find(OldName);
	};
	return S1;
}

int main() {
	string S1 = "Wlecome to Jordan , Jordan is a nice country";

	cout << "Original String \n" << S1 << endl;
	cout << "\nString after Replace words :\n";

	cout << ReplaceWordInStringUsingBuiltInFunction(S1, "Jordan", "USA") << "\n\n";

	return 0;
}



