#include <bits/stdc++.h>
using namespace std;

bool comp(pair <string, int>& a, pair <string, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	
	int n; cin >> n;

	map <string, int> mp;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		mp.insert({ s,0 });
	}
	string token;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);

		istringstream iss(str);
		while (getline(iss, token, ' ')) {
			if (token != " ") {
				mp[token]++;
			}
		}
	}

	vector <pair <string, int>> vc(mp.begin(), mp.end());

	sort(vc.begin(), vc.end(), comp);

	for (auto i : vc)
		cout << i.first << " " << i.second << endl;
}