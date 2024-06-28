#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stInfoPerson {
	string NumberAccount;
	string CodePin;
	string Name;
	string Phone;
	double AccountBalance = 0;
};

vector <string> SplitString(string S1, string Seperator) {
	short pos = 0;
	string sWord;
	vector <string> vString;

	while ((pos = S1.find(Seperator)) != std::string::npos) 
	{
		sWord = S1.substr(0, pos);

		if (sWord != "") 
			vString.push_back(sWord);
		
		S1.erase(0, pos + Seperator.length());
	}

	if (S1 != "")
		vString.push_back(S1);

	return vString;
}

stInfoPerson ConvertLineToRecord(string S1, string Seperator = "#//#") {
	stInfoPerson client;
	vector <string> vString;

	vString = SplitString(S1, Seperator);

	client.NumberAccount = vString[0];
	client.CodePin = vString[1];
	client.Name = vString[2];
	client.Phone = vString[3];
	client.AccountBalance = stod(vString[4]);
	return client;
}
void PrintClentRecord(stInfoPerson client) {

	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccount Number : " << client.NumberAccount;
	cout << "\nCode Pin : " << client.CodePin;
	cout << "\nName : " << client.Name;
	cout << "\nPhone : " << client.Phone;
	cout << "\nAccount Balance : " << client.AccountBalance << endl;
}
int main() {
	string stLine = "A150#//#1234#//#issam bourouail#//#537328928#//#4376.000330";
	cout << "Line Record is \n";
	cout << stLine;

	stInfoPerson Person1;
	Person1 = ConvertLineToRecord(stLine, "#//#");
	PrintClentRecord(Person1);

	return 0;
}



