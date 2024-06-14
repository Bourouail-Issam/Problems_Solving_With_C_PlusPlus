
#include <iostream>
#include <cmath>
using namespace std;

int ReadAge() {

	short unsigned Age;
	cout << "Please Enter Your Age : ";
	cin >> Age;
	return Age;
}
bool ValidationNumberInRange(int Number, int From, int To) {
	return (Number >= From && Number <= To);
}
int ReadUntilAgeBetween(int From , int To) {
	short unsigned Age =0;
	do
	{	
		Age = ReadAge();

	} while (!ValidationNumberInRange(Age, From,To));
	return Age;
}
void PrintResult(int Age) {
		cout << "\nYour Age is " << Age << endl;
}
int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));
}
