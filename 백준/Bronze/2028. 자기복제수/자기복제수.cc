#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int tc; cin >> tc;

	for (int i = 0; i < tc; i++) {
		int n; cin >> n;
		int pown = pow(n, 2);

		string origin = to_string(n);
		string s = to_string(pown);

		bool ans = true;

		for (int i = s.length() - origin.length(), j = 0; i < s.length(); i++, j++) {
			// cout << "origin : " << origin[j] << " / pow : " << s[i] << endl;
			if (origin[j] != s[i])
				ans = false;
		}

		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}