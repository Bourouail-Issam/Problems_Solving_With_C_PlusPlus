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

		while (getline(MyFill, line)) {
		
			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);
		}
		MyFill.close();
	}
	return vClients;
}
void PrintClient(stInfoPerson clientInfo) {
	cout << "| " << setw(15) << left << clientInfo.NumberAccount;
	cout << "| " << setw(10) << left << clientInfo.CodePin;
	cout << "| " << setw(40) << left << clientInfo.Name;
	cout << "| " << setw(12) << left << clientInfo.Phone;
	cout << "| " << setw(12) << left << clientInfo.AccountBalance;
}
void PrintAllClients(vector <stInfoPerson>& V_st_Client) {
	
	cout << "\n\t\t\t\t\t Client List (" << V_st_Client.size() << ") client(s).\n";
	cout << "\n-------------------------------------------------------------------------------------------------\n\n";
	cout << "| " << left << setw(15)  << "Accout Number";
	cout << "| " << left << setw(10)  << "Pin Code";
	cout << "| " << left << setw(40)  << "Client Name";
	cout << "| " << setw(12) << left << "Phone";
	cout << "| " << setw(12) << left << "Balance";
	cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
	
	for (stInfoPerson& infoClient : V_st_Client) {
		PrintClient(infoClient);
		cout << endl;
	}
	cout << "\n-------------------------------------------------------------------------------------------------\n\n";
}
int main() {
	vector <stInfoPerson> vClients = LoadClientsDataFromFile(ClinetsFileName);
	
	PrintAllClients(vClients);
	return 0;
}



