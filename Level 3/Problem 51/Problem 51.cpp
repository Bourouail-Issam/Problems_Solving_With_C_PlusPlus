#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClinetsFileName = "MyFill.txt";
struct stInfoPerson {
	string NumberAccount;
	string CodePin;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool MarkForDelete = false;
	bool MarkForUpDate = false;
};
vector <string> SplitString(string S1, string Delim = "#//#") {
	size_t pos = 0;
	string sWord;
	vector <string> vClientInfo;
	while ((pos = S1.find(Delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);
		if (sWord != "")
			vClientInfo.push_back(sWord);
		S1 = S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
		vClientInfo.push_back(S1);
	return vClientInfo;
}
stInfoPerson ConvertLineToRecord(string Line, string Seperator = "#//#") {
	stInfoPerson stClient;
	vector <string> vClientInfo;

	vClientInfo = SplitString(Line);

	stClient.NumberAccount = vClientInfo[0];
	stClient.CodePin = vClientInfo[1];
	stClient.Name = vClientInfo[2];
	stClient.Phone = vClientInfo[3];
	stClient.AccountBalance = stod(vClientInfo[4]);
	return stClient;
};
vector <stInfoPerson> LoadClientsDataFromFile(string ClientsFileName) {
	vector <stInfoPerson> vClients;
	fstream MyFill;

	MyFill.open(ClientsFileName, ios::in);
	if (MyFill.is_open()) {

		stInfoPerson Client;
		string line;

		while (getline(MyFill, line)) {

			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);
		}
		MyFill.close();
	}
	return vClients;
}

void PrintClient(stInfoPerson clientInfo) {
	cout << "\nThe Following are the client details:\n\n";
	cout << setw(16) << left << "Accout Number" << ": " << clientInfo.NumberAccount << endl;
	cout << setw(16) << left << "Pin Code" << ": " << clientInfo.CodePin << endl;
	cout << setw(16) << left << "Client Name" << ": " << clientInfo.Name << endl;
	cout << setw(16) << left << "Phone" << ": " << clientInfo.Phone << endl;
	cout << setw(16) << left << "Account Balance" << ": " << clientInfo.AccountBalance << endl;
}
string ReadClientAccountNumber() {
	string AccountNumber;
	cout << "Please Enter Account Number : ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, stInfoPerson& client, vector <stInfoPerson>& vClients) {
	for (stInfoPerson& infoClient : vClients) {
		if (infoClient.NumberAccount == AccountNumber) {
			client = infoClient;
			return true;
		}
	}
	return false;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stInfoPerson>& vClients) {

	for (stInfoPerson& infoClient : vClients) {

		if (infoClient.NumberAccount == AccountNumber) {
			infoClient.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
string ConvertRecordToLine(stInfoPerson& client, string Seperator = "#//#") {
	string Line;
	Line += client.NumberAccount + Seperator;
	Line += client.CodePin + Seperator;
	Line += client.Name + Seperator;
	Line += client.Phone + Seperator;
	Line += to_string(client.AccountBalance);
	return Line;
}

vector <stInfoPerson> SaveClientsDataToFile(string FileName, vector <stInfoPerson>& vClient) {
	fstream MyFill;
	MyFill.open(FileName, ios::out);

	if (MyFill.is_open()) {

		string DataLine;

		for (stInfoPerson& line : vClient) {

			if (!line.MarkForDelete) {

				DataLine = ConvertRecordToLine(line);
				MyFill << DataLine << endl;
			}
		}
		MyFill.close();
	}
	return vClient;
}

stInfoPerson ChangeClientRecord(string NumberAccount) {
	stInfoPerson client;
	client.NumberAccount = NumberAccount;

	cout << "\n\nEnter PinCode ? ";
	getline(cin >> ws , client.CodePin);

	cout << "Enter Name? ";
	getline(cin , client.Name);

	cout << "Enter Phone? ";
	getline(cin, client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> client.AccountBalance;

	return client;
}

vector <stInfoPerson> SaveCleintsDataToFile(string FileName, vector <stInfoPerson>& vClient) {
	fstream MyFill;
	MyFill.open(FileName, ios::out);

	if (MyFill.is_open()) {
		string Dataline;

		for (stInfoPerson stClient : vClient)
		{
			if (!stClient.MarkForDelete) 
			{
				Dataline = ConvertRecordToLine(stClient);
				MyFill << Dataline << endl;
			}
		}
		MyFill.close();
	}
	return vClient;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector <stInfoPerson>& vClient) {

	stInfoPerson client;

	if (FindClientByAccountNumber(AccountNumber, client, vClient)) {
		PrintClient(client);

		char UpDateClient = 'n';
		cout << "\nAre You sure you want update this client y/n ? ";
		cin >> UpDateClient;

		if (tolower(UpDateClient) == 'y') {

			for (stInfoPerson& stClient : vClient) 
			{
				if (stClient.NumberAccount == AccountNumber)
				{
					stClient = ChangeClientRecord(AccountNumber);
					break;
				}
			}
		
			SaveCleintsDataToFile(ClinetsFileName, vClient);

			cout << "\n\nClient UpDated Successfully\n\n";
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n\n";
		return false;
	}
}

int main() {

	vector <stInfoPerson> vClient = LoadClientsDataFromFile(ClinetsFileName);
	string NumberAccout = ReadClientAccountNumber();
	UpdateClientByAccountNumber(NumberAccout, vClient);

	return 0;
}



