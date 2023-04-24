#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> vc(5);
	for (int i = 0; i < 5; i++) {
		cin >> vc[i];
	}

	sort(vc.begin(), vc.end());
	cout << (accumulate(vc.begin(), vc.end(), 0) / 5) << endl;
	cout << vc[2];
}