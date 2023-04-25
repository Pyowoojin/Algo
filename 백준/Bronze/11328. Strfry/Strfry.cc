#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
	int tc; cin >> tc;

	while (tc--) {
		string s1, s2; cin >> s1 >> s2;

		for (int i = 0; i < s1.length(); i++) {
			arr[s1[i] - 'a']++;
		}
		for (int i = 0; i < s2.length(); i++) {
			arr[s2[i] - 'a']--;
		}

		bool ans = true;
		for (int i = 0; i < 26; i++) {
			if (arr[i] != 0)
				ans = false;
		}

		if (ans)
			cout << "Possible\n";
		else {
			cout << "Impossible\n";
		}

		fill(arr, arr + 26, 0);
	}
}