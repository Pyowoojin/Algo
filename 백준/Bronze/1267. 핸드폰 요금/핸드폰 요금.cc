#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector <int> vc(n);

	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}

	int young = 0, min = 0;
	for (int i = 0; i < vc.size(); i++) {
		int tvc = 0;
		int z = 0;
		while (tvc < vc[i]) {
			young += 10;
			tvc += 29 + z;
			z = 1;
		}
	}

	for (int i = 0; i < vc.size(); i++) {
		int tvc = 0;
		int z = 0;
		while (tvc < vc[i]) {
			min += 15;
			tvc += 59 + z;
			// cout << tvc << endl;
			z = 1;
		}
	}

	if (young == min)
		cout << "Y M " << min;
	else if (young > min)
		cout << "M " << min;
	else
		cout << "Y " << young;
}