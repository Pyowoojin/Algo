#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	set <string> st;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		st.insert(s);
	}

	cout << n - st.size();
}