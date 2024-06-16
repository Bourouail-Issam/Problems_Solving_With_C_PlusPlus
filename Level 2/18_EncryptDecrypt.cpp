
#include <iostream>
#include <string>
using namespace std;

string ReadeName(string message) {
    string Text = "";
    cout << message;
    getline(cin, Text);
    return Text;
}
string Encryption(string Text, const short EncryptionKey) {
    
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char( (int)Text[i] + EncryptionKey);
    }

    return Text;
}
string Decryption(string Text, const short EncryptionKey) {

    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }

    return Text;
}
int main()
{
    const short EncryptionKey = 2344;
    string NameBeforeEncryption = ReadeName("Please Enter Text : ");
    string NameAfterEncryption = Encryption(NameBeforeEncryption, EncryptionKey);
    string NameAfterDecryption = Decryption(NameAfterEncryption, EncryptionKey);
    cout << "Text Befor Encryption is : " << NameBeforeEncryption << endl;
    cout << "Text After Encryption is : " << NameAfterEncryption << endl;
    cout << "Text After Encryption is : " << NameAfterDecryption << endl;
}

