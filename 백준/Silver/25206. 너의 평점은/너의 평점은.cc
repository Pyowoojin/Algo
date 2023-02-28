#include <bits/stdc++.h>
using namespace std;

int pCount;

double ReturnGrade(int credit, string grade) {
	if (grade == "A+") {
		return credit * 4.5;
	}
	else if (grade == "A0") {
		return credit * 4.0;
	}
	else if (grade == "B+") {
		return credit * 3.5;
	}
	else if (grade == "B0") {
		return credit * 3.0;
	}
	else if (grade == "C+") {
		return credit * 2.5;
	}
	else if (grade == "C0") {
		return credit * 2.0;
	}
	else if (grade == "D+") {

		return credit * 1.5;
	}
	else if (grade == "D0") {
		return credit * 1.0;
	}
	else if (grade == "F") {
		return 0;
	}
	else if (grade == "P") {
		pCount += credit;
		return 0;
	}
}

int main() {

	double totalrGrade = 0;
	int realTotGr = 0;
	cout << fixed;
	cout.precision(6);

	for (int i = 0; i < 20; i++) {
		string lectureName;
		double credit; string grade;
		cin >> lectureName >> credit >> grade;
		realTotGr += (int)(credit);
		totalrGrade += ReturnGrade(credit, grade);
	}
	cout << totalrGrade / (realTotGr - pCount);
}