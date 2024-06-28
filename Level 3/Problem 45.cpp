#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stInfoPerson 
{
	string NumberAccount;
	string CodePin;
	string Name = "";
	string Phone;
	double AccountBalance = 0;
};

stInfoPerson ReadNewClient(){
	stInfoPerson Person1;

	cout << "Please enter Account Number ?\n";
	getline(cin, Person1.NumberAccount);

	cout << "Please Code pin ?\n";
	getline(cin, Person1.CodePin);

	cout << "Please enter Your Name ?\n";
	getline(cin, Person1.Name);

	cout << "Please enter Account balance?\n";
	cin >> Person1.AccountBalance;

	return Person1;
}

string ConvertRecordToLine(stInfoPerson Client, string Seperato = "#//#") {
	string stClientRecord = "";

	stClientRecord += Client.NumberAccount + Seperato;
	stClientRecord += Client.CodePin + Seperato;
	stClientRecord += Client.Name + Seperato;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main() {
	stInfoPerson Person1;

	Person1 = ReadNewClient();
	cout << "\n\nClient Record for saving is :\n";
	cout << ConvertRecordToLine(Person1) << endl;

	return 0;
}



