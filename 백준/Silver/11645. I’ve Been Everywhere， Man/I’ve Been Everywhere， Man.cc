#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k; cin >> k;

	for (int i = 0; i < k; i++) {
		int n; cin >> n;
		set <string> s;

		for (int i = 0; i < n; i++) {
			string s1; cin >> s1;
			s.insert(s1);
		}

		cout << s.size() << endl;
	}

}