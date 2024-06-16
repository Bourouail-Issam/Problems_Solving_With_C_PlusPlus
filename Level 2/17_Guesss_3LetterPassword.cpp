#include <iostream>
using namespace std;


string Read_3_Letter(string message)
{
    string password;
    cout << message;
    cin >> password;
    return password;
}

bool Guess3letterPassword(string word)
{
	string PasswordGuess = "";
	int counter = 0;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++) {

			for (int z = 65; z <= 90; z++) {

				PasswordGuess = PasswordGuess + char(i);
				PasswordGuess = PasswordGuess + char(j);
				PasswordGuess = PasswordGuess + char(z);

				counter++;
				cout << "Trial [" << counter << "] : " << PasswordGuess << endl;

				if (PasswordGuess == word) {
					cout << "\nPassword is " << PasswordGuess << "\nFound after " 
						 << counter << " Trial(s)";
					return true;
				}

				PasswordGuess = "";
			}
		}
	}
}
int main() {
    string word = Read_3_Letter("Please Enter 3 Letter Upercase : ");
    Guess3letterPassword(word);
    return 0;
}