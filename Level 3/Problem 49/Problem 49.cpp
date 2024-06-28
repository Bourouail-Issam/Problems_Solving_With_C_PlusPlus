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
	double AccountBalance =0;
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
	if (MyFill.is_open())
	{
		stInfoPerson Client;
		string line;

		while (getline(MyFill, line)) 
		{
			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);
		}

		MyFill.close();
	}
	return vClients;
}

void PrintClient(stInfoPerson clientInfo) {
	cout << "The Following are the client details:\n\n";
	cout << setw(16) << left << "Accout Number" << ": " << clientInfo.NumberAccount << endl;
	cout << setw(16) << left << "Pin Code" << ": " << clientInfo.CodePin << endl;
	cout << setw(16) << left << "Client Name" << ": " << clientInfo.Name << endl;
	cout << setw(16) << left << "Phone" << ": " << clientInfo.Phone << endl;
	cout << setw(16) << left << "Account Balance" << ": " << clientInfo.AccountBalance << endl;
}
string ReadClientAccountNumber(){
	string AccountNumber;
	cout << "Please Enter Account Number : ";
	cin >> AccountNumber;
	return AccountNumber;
}
bool FindClientByAccountNumber(string AccountNumber, stInfoPerson& client){

	vector <stInfoPerson> vClients = LoadClientsDataFromFile(ClinetsFileName);

	for (stInfoPerson& infoClient : vClients) {
		if (infoClient.NumberAccount == AccountNumber) {
			client = infoClient;
			return true;
		}
	}
	return false;
}

int main() {
	
	string AccountNumber = ReadClientAccountNumber();

	stInfoPerson client;
	
	if (FindClientByAccountNumber(AccountNumber, client)) {
		cout << endl;
		PrintClient(client);
	}
	else
		cout << "\nClient wit Account Number (" << AccountNumber << ") Not Found!\n\n";
	return 0;
}



