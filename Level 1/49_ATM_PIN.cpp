
#include <iostream>
using namespace std;

string  ReadPassword(string Msg) {

	string PassWord = "";
	cout << Msg;
	cin >> PassWord;
	return PassWord;
}
bool  Login() {
	string PassWord = ReadPassword("Please Enter PIN Code : ");
	do {
		if (PassWord != "1234") {
			system("color 4F");
			cout << "Wrong PIN \nPlease Enter PIN code : ";
			cin >> PassWord;
		}
	} while (PassWord != "1234");
	return true;
}
int main()
{
	if (Login()) {
		system("color 2F");
		cout << "Your Balance is 7500" << endl;
	}
	
	return 0;
}

