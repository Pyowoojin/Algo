#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << "";
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map <string, string> password;

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s1, s2; cin >> s1 >> s2;
		password.insert({ s1,s2 });
	}

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		cout << password[s] << '\n';
	}
}