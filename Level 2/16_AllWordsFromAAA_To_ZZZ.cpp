
#include <iostream>
#include <string>
using namespace std;

void PrintAllWords() {
	cout << "\n";
	string word = "";

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++) {

			for (int z = 65; z <= 90; z++) {
				word = word + char(i);
				word = word + char(j);
				word = word + char(z);

				cout << word << "\n";

				word = "";
			}
			cout << endl;
		}
		cout << "\n__________________________________\n";
	}
}
int main()
{
	PrintAllWords();
}
