#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool SortingWord(vector <string> Words, string Alphabic)
{
    int WordsL = Words.size();
    
    if (WordsL == 1)
        return true;

    for (int i = 0; i < Words.size(); i++)
    {
        if (Words.size() <= i + 1) {
            return true;
        }
        string Word1 = Words[i];
        string Word2 = Words[i + 1];

        int pos1 = 0, pos2 = 0;
        if (Word2 != "") {

            int wordL = Word1.length();

            for (int j = 0; j < wordL; j++)
            {
                if (j < Word2.size()) {
                    if ((pos1 = Alphabic.find(Word1[j])) < (pos2 = Alphabic.find(Word2[j])))
                        break;
                    if ((pos1 = Alphabic.find(Word1[j])) > (pos2 = Alphabic.find(Word2[j])))
                        return false;
                }
                else {
                    return false;
                }

            }
        }
    }
    return true;
}

int main()
{
    string alphabic = "abcdefghigklmnopqrstuvwxyz";
    vector <string> Words{ "app", "appel","ban", "banana" };

    SortingWord(Words, alphabic) ? cout << "True" : cout << "false";

}



