#include <iostream>
using namespace std;

string  ReadPositiveNumber(string Msg) {

	string PassWord = "";
	cout << Msg;
	cin >> PassWord;
	return PassWord;
}
bool  Login() {
	string PassWord = "";
	short counter = 3;
	do {
		PassWord = ReadPositiveNumber("Please Enter PIN Code : ");
		counter--;
		if (PassWord == "1234")
			return 1;
		else  {
			system("color 4F");
			cout << "Wrong PIN You have " << counter << " more tries\n";
		}

	} while (PassWord != "1234" && counter > 0);
	return 0;
}
int main()
{
	if (Login()) {
		system("color 2F");
		cout << "Your Balance is 7500" << endl;
	}
	else {
		cout << "\nYou Card is blocked call the bank for help\n";
	}
	return 0;
}

