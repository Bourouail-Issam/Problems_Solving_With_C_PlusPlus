#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct stMyDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

string ReadStringDate(string Message) {
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);
    
    return DateString;
}
//------------------------

vector <string> SplitString(string S1, string Delim = "#//#") {

    size_t pos = 0;
    string sWord;
    vector <string> MyDate;

    while ((pos = S1.find(Delim)) != std::string::npos) {

        sWord = S1.substr(0, pos);

        if (sWord != "")
            MyDate.push_back(sWord);

        S1 = S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
        MyDate.push_back(S1);

    return MyDate;
}
stMyDate StringToDateStructure(string Line) {

    stMyDate stDate;
    vector <string> vStringDate;

    vStringDate = SplitString(Line, "/");

    stDate.Day = stoi(vStringDate[0]);
    stDate.Month = stoi(vStringDate[1]);
    stDate.Year = stoi (vStringDate[2]);

    return stDate;
};
//------------------------
string DateToString(stMyDate Date, string Seperator = "#//#") {

    string stringDate;
    stringDate += to_string(Date.Day) + Seperator;
    stringDate += to_string(Date.Month) + Seperator;
    stringDate += to_string(Date.Year);

    return stringDate;
}


int main()
{
    string Date = ReadStringDate("Pease enter Date dd/mm/yyyy : ");
   

    stMyDate stDate =  StringToDateStructure(Date);

    //use printf
    printf("Day : %d\nMonth : %d\nYear : %d\n", stDate.Day, stDate.Month, stDate.Year);
    
    //use cout 
    //cout << "\Day : " << stDate.Day << endl;
    //cout << "Month : " << stDate.Month << endl;
    //cout << "Year : " << stDate.Year << endl;

    string stringDate = DateToString(stDate,"/");
    cout << "\nYou Entered : " << stringDate << "\n";

    system("pause>0");
    return 0;
}
