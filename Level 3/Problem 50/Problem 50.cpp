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
vector <stInfoPerson> LoadClientsDataFromFile(string ClinetsFileName) {
	vector <stInfoPerson> vClients;
	fstream MyFill;

	MyFill.open(ClinetsFileName, ios::in);
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
	for (stInfoPerson& infoClient : vClients)
	{
		if (infoClient.NumberAccount == AccountNumber)
		{
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

vector <stInfoPerson> SaveClientsDataToFile(string FileName , vector <stInfoPerson>& vClient) {
	fstream MyFill;
	MyFill.open(FileName, ios::out);

	if (MyFill.is_open()) {

		string DataLine;

		for(stInfoPerson& line : vClient){

			if (!line.MarkForDelete) {

				DataLine = ConvertRecordToLine(line);
				MyFill << DataLine << endl;
			}
		}
		MyFill.close();
	}
	return vClient;
}

bool DeleteClient(string AccountNumber, vector <stInfoPerson>& vClient){

	char Answer = 'n';
	stInfoPerson client;

	if(FindClientByAccountNumber(AccountNumber, client, vClient)) 
	{
		PrintClient(client);

		cout << "\nAre you sure you want to delete this client y/n ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
			SaveClientsDataToFile(ClinetsFileName,vClient);
			vClient = LoadClientsDataFromFile(ClinetsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n\n";
		return false;
	}

}
int main() {
	vector <stInfoPerson> vClient = LoadClientsDataFromFile(ClinetsFileName);
	string NumberAccout = ReadClientAccountNumber();
	DeleteClient(NumberAccout, vClient);
	return 0;
}



