#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


char ReadChar() {
	char letter;
	cout << "\nPlease Enter a Character : ";
	cin >> letter;
	return letter;
}

bool isVowelCharacter(char ch1) {
	ch1 = tolower(ch1);
	return((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}

int main() {
	
	char Letter = ReadChar();
	if (isVowelCharacter(Letter))
		printf("Yes Letter '%c' is vowel \n", Letter);
	else
		printf("No Letter '%c' is NOT vowel \n", Letter);
	system("pause>0");
}

