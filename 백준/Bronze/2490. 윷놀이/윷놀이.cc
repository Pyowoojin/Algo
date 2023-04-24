#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int tot = 0;
		for (int z = 0; z < 4; z++) {
			int c; cin >> c;
			tot += c;
		}

		if (tot == 3) {
			cout << "A\n";
		}
		else if (tot == 2) {
			cout << "B\n";
		}
		else if (tot == 1) {
			cout << "C\n";
		}
		else if (tot == 0) {
			cout << "D\n";
		}
		else
			cout << "E\n";
	}
}