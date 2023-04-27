#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	set <string> rainbow;
	rainbow.insert("ChongChong");

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string s1, s2; cin >> s1 >> s2;

		if (rainbow.find(s1) != rainbow.end()) {
			rainbow.insert(s2);
		}
		if(rainbow.find(s2)!= rainbow.end()) {
			rainbow.insert(s1);
		}
	}

	cout << rainbow.size();

}