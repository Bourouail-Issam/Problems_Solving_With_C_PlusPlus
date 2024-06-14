
#include <iostream>
#include <string>
using namespace std;

struct strInfos
{
    string FirstName;
    string lastName;
};

strInfos ReadFullName() {

    strInfos FullName;
    cout << "Please Enter Your First Name : ";
    getline(cin, FullName.FirstName);
    cout << "Please Enter Your Last Name : ";
    getline(cin, FullName.lastName);
    return FullName;
}

string concatenationFullName(strInfos fullName, bool direction) {

    string result = "";

    if (direction)
    {
        result = fullName.FirstName + " " + fullName.lastName;
        return result;
    }
    else 
    {
        result = fullName.lastName + " "+ fullName.FirstName;
        return result;
    }
}
void printInfo(strInfos fullName) {

    cout << "Your Name is " << concatenationFullName(fullName, false);
}
int main()
{
    printInfo(ReadFullName());
}
