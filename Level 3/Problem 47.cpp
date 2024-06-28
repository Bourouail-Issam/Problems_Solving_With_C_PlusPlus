#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClinetsFileName = "MyFill";
struct stInfoPerson 
{
	string NumberAccount;
	string CodePin;
	string Name;
	string Phone;
	double AccountBalance = 0;
}; 

stInfoPerson ReadNewClient() {
	stInfoPerson Person1;

	cout << "Please enter Account Number ?\n";
	getline(cin >> ws, Person1.NumberAccount);

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
void AddInfonAccoutToMyFill (string SourceName, string data){

	fstream MyFill;

	MyFill.open(SourceName, ios::out | ios::app);

	if (MyFill.is_open()) 
	{
		MyFill << data << endl;
		MyFill.close();
	}
}
void AddNewClient() {
	stInfoPerson stClient;
	stClient = ReadNewClient();
	AddInfonAccoutToMyFill(ClinetsFileName, ConvertRecordToLine(stClient, "#//#"));
}
void AddClients() {
	char AddMore = 'Y';
	do {
		system("cls");

		cout << "Adding New Client : \n\n";
		AddNewClient();

		cout << "\n\nClinet Added Successfully, do you want to add more clients? (Y/N) : ";
		cin >> AddMore;

	} while (tolower(AddMore) == 'y');
}
int main() {
	AddClients();
	return 0;
}



