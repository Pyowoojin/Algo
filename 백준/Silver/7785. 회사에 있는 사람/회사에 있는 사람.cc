#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	set <string> st;

	for (int i = 0; i < n; i++) {
		string s, doit; cin >> s >> doit;

		if (doit == "enter") {
			st.insert(s);
		}
		else if (doit == "leave") {
			st.erase(s);
		}
	}

	for (auto iter = st.rbegin(); iter != st.rend(); iter++)
		cout << *iter << '\n';


	return 0;
}