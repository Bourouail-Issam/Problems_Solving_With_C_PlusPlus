
#include <iostream>
#include <string>
using namespace std;

string readName() {
	string Name;
	cout << "Please enter your name : ";
	getline(cin, Name);
	return Name;
}
void printName(string PrintName) {

	cout << "\nYour name is " << PrintName << endl;
}
int main()
{
	printName(readName());
}

