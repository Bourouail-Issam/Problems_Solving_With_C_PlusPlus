
#include <iostream>
using namespace std;

float ReadNumberInRange(int from, int to) {

	float GradeNumber;
	do {
		cout << "Please Enter Your Grade : ";
		cin >> GradeNumber;
	} while (GradeNumber < from || GradeNumber > to);

	return GradeNumber;
}
char checkGrade(float GradeNumber) {

	if (GradeNumber >= 90)
		return 'A';
	if (GradeNumber >= 80)
		return 'B';
	if (GradeNumber >= 70)
		return 'C';
	if (GradeNumber >= 60)
		return 'D';
	if (GradeNumber >= 50)
		return 'E';
	else
		return 'F';
}
void PrintGrade( float GradeNumber) {
	cout << "Grade of " << GradeNumber <<" is " << checkGrade(GradeNumber);
}
int main()
{
	PrintGrade(ReadNumberInRange(0,100));
	return 0;
}

