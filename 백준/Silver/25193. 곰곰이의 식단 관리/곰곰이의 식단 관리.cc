#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;
	
	int otherChar = 0;
	int cChar = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] != 'C')
			otherChar++;
	}
	cChar = n - otherChar;
	/*
	int ans = 1;

	for (int i = 0, j = 0; i < cChar; i++, j++) {
		//cout << "i : " << i;
		//cout << "  //  j : " << j << endl;
		if (j == otherChar + 1) {
			ans++;
			j = 0;
		}
	}*/

	int ans;
	if (!otherChar)
		cout << n;
	else {
		ans = cChar / (otherChar + 1);
		if (cChar % (otherChar + 1) != 0) {
			ans++;
			cout << ans;
		}
		else
			cout << ans;
	}

}


