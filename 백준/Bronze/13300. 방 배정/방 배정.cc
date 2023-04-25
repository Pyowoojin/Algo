#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;

	vector <int> man(6);
	vector <int> woman(6);
	int totalRoom = 0;

	for (int i = 0; i < n; i++) {
		bool s; int grade;
		cin >> s >> grade;
		if (s == 0) {
			woman[grade - 1]++;
		}
		else {
			man[grade - 1]++;
		}
	}

	for (int i = 0; i < 6; i++) {
		totalRoom += (man[i] / k);
		totalRoom += (man[i] % k);

		totalRoom += (woman[i] / k);
		totalRoom += (woman[i] % k);
	}

	cout << totalRoom;
}