#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
enum enWhatToCount {SmallLetter =0, CapitalLetter =1, All =3 };

string ReadString() {
	string letter;
	cout << "Please Enter a string ?\n";
	getline(cin, letter);
	return letter;

}
short CountLetter(string paragraph, enWhatToCount whatToCount = enWhatToCount::All ) {

	if (whatToCount == enWhatToCount::All)
		return paragraph.length();

	int count = 0;
	for (int i = 0; i < paragraph.length(); i++) {
		if (whatToCount == enWhatToCount::CapitalLetter && isupper(paragraph[i]))
			count++;
		else if (whatToCount == enWhatToCount::SmallLetter && islower(paragraph[i]))
			count++;
	}
	return count;
}
int CountCapitalLetter(string  Paragraph) {
	int count = 0;
	for (int i = 0; i < Paragraph.length(); i++) {
		if (isupper(Paragraph[i]))
			count++;
	}
	return count;
}

int CountSmallLetter(string Paragraph) {
	int count = 0;
	for (int i = 0; i < Paragraph.length(); i++) {
		if (islower(Paragraph[i]))
			count++;
	}
	return count;
}

int main() {
	string paragraph = ReadString();
	
	cout << "\nString Length = " << CountLetter(paragraph);
	cout << "\nCapital Letters count = " << CountLetter(paragraph,enWhatToCount::CapitalLetter);
	cout << "\nSmall Letters count = " << CountLetter(paragraph, enWhatToCount::SmallLetter) << endl;

	return 0;
}

