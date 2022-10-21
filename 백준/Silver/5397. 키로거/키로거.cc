#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		list <char> list;
		string s; cin >> s;

		auto it = list.begin();

		for (int k = 0; k < s.length(); k++) {
			if (s[k] == '<') {
				if (it != list.begin())
					it--;
			}
			else if (s[k] == '>') {
				if (it != list.end())
					it++;
			}
			else if (s[k] == '-') {
				if (list.size() != 0) {
					if (it != list.begin()) {
						it = list.erase(--it);
					}
				}
			}
			else {
				list.insert(it, s[k]);
			}
		}

		for (auto z : list)
			cout << z;
		if(i+1 != n)
			cout << '\n';
	}
}

