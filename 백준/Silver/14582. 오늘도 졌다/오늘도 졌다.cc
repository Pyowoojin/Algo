#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> wool(9), geol(9);
	bool yuk = false;
	bool winning = false;

	int woolScore = 0, geolScore = 0;

	for (int i = 0; i < 9; i++) {
		cin >> wool[i];
	}

	for (int i = 0; i < 9; i++) {
		cin >> geol[i];
	}

	for (int i = 0; i < 9; i++) {
		woolScore += wool[i];
		if (woolScore > geolScore) {
			winning = true;
		}
		geolScore += geol[i];
		if (woolScore < geolScore && winning) {
			yuk = true;
		}
	}

	if (yuk)
		cout << "Yes";
	else
		cout << "No";
}