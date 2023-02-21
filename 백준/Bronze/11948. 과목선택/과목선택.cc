#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> vc1;
	vector <int> vc2;

	for (int i = 0; i < 4; i++) {
		int c; cin >> c;
		vc1.push_back(c);
	}
	for (int i = 0; i < 2; i++) {
		int c; cin >> c;
		vc2.push_back(c);
	}

	sort(vc1.begin(), vc1.end(), greater<>());
	sort(vc2.begin(), vc2.end(), greater<>());

	int total = 0;
	total += vc1[0] + vc1[1] + vc1[2] + vc2[0];

	cout << total;
}