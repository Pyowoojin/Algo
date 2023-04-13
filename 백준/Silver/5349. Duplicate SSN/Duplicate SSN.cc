#include <bits/stdc++.h>
using namespace std;

int main() {
	set <string> st;
	set <string> ans;
	while (1) {
		string s; cin >> s;
		if (s == "000-00-0000")
			break;

		if (st.find(s) == st.end()) {
			st.insert(s);
		}
		else {
			ans.insert(s);
		}
	}
	for (auto i : ans)
		cout << i << '\n';
}