
#include <iostream>
using namespace std;

struct strInfo
{
	short unsigned Age;
	bool HasDriveLicense;
};

strInfo readInfo()
{
	strInfo UserInfo;
	cout << "Please Enter Your Age : ";
	cin >> UserInfo.Age;
	cout << "Please enter 1 if you have a drive License and 0 if not : ";
	cin >> UserInfo.HasDriveLicense;
	return UserInfo;
}
bool IsAccepted(strInfo info) {

	return (info.Age > 21 && info.HasDriveLicense);
}
void printResult(strInfo result) {
	if (IsAccepted(result)) {
		cout << "\nHired\n";
	}
	else {
		cout << "\nRejected\n";
	}
}

int main()
{
	printResult(readInfo());
	return 0;
}


