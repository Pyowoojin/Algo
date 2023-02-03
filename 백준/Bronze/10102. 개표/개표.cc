#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	string s; cin >> s;

	int aCnt = 0, bCnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A')
			aCnt++;
		else
			bCnt++;
	}

	if (aCnt > bCnt)
		cout << 'A';
	else if (aCnt < bCnt)
		cout << 'B';
	else
		cout << "Tie";

	
}