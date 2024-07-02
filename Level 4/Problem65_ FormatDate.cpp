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
    stDate.Year = stoi(vStringDate[2]);

    return stDate;
};
//------------------------
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) 
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos) {

        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace); //find next    
    }

   return S1;
    
}
//------------------------
string formatDate(stMyDate date, string DateFormat = "dd/mm/yyyy") 
{
    string FormattedDateString = "";

    
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(date.Year));

    return FormattedDateString;
}

int main()
{
    string Date = ReadStringDate("Pease enter Date dd/mm/yyyy : ");


    stMyDate stDate = StringToDateStructure(Date);

    cout << "\n" << formatDate(stDate) << "\n";

    cout << "\n" << formatDate(stDate, "yyyy/dd/mm") << "\n";

    cout << "\n" << formatDate(stDate, "mm/dd/yyyy") << "\n";

    cout << "\n" << formatDate(stDate, "mm-dd-yyyy") << "\n";

    cout << "\n" << formatDate(stDate, "dd-mm-yyyy") << endl;

    cout << "\n" << formatDate(stDate, "Day:dd, Month:mm, Year:yyyy") << "\n";
    


    system("pause>0");
    return 0;
}
