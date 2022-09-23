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

	int maxN, quiz; cin >> maxN >> quiz;

	unordered_map <string, int> poket;
	unordered_map <int, string> poketInt;

	for (int i = 0; i < maxN; i++) {
		string s; cin >> s;
		poket.insert({ s, i + 1 });
		poketInt.insert({ i + 1, s });
	}

	for (int i = 0; i < quiz; i++) {
		string s; cin >> s;
		if (isdigit(s[0])) {
			int t = stoi(s);
			cout << poketInt[t] << '\n';
		}
		else {
			cout << poket[s] << '\n';
		}
	}
}