#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString (){
	string S1;
	cout << "Please Enter Your String ?\n";
	getline(cin, S1);
	return S1;
}
vector <string> SplitString(string S1, string delim){

	vector<string> vString;
	int pos = 0;
	string sWord;

	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (S1 != "")
			vString.push_back(sWord);

		S1.erase(0, pos + delim.length());
	}

	if(S1 != "")
		vString.push_back(S1);

	return vString;
}

string ReverseString(string S1) {
	string S2 = "";
	vector <string> vString;

	vString = SplitString(S1, " ");

    //Declare iterator
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin()) {
		--iter;
		S2 += *iter + " ";
	}
	return S2.substr(0, S2.length()-1);
}

int main() {
	string S1 = ReadString();
	cout << "\nString after revesing words :\n";
	cout << ReverseString(S1) << "\n\n";

	return 0;
}



