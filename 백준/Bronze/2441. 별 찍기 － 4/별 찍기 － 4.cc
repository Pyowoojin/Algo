#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;

	for (int i = n; i > 0; i--) {
		for (int k = n; k > i; k--) {
			cout << " ";
		}

		for (int j = i; j > 0; j--) {
			cout << "*";
		}
		cout << endl;
	}

}