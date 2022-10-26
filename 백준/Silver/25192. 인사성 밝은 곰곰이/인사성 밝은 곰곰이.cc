#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set <string> mp;

	int n; cin >> n;
	int gomgom = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "ENTER") {
			mp.clear();
		}

		else if (mp.find(s) != mp.end()) {
			continue;
		}
		else if (mp.find(s) == mp.end()) {
			mp.insert(s);
			gomgom++;
		}
	}
	cout << gomgom;
	
}


