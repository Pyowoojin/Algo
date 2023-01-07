#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	
	int total = 0;

	while (tc) {
		string s; cin >> s;

		int c = stoi(s.substr(2, 5));
		
		if (c <= 90)
			total++;

		tc--;
	}
	cout << total;
}