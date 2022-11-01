#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map <char, string> mp;

	mp['0'] = "zero";
	mp['1'] = "one";
	mp['2'] = "two";
	mp['3'] = "three";
	mp['4'] = "four";
	mp['5'] = "five";
	mp['6'] = "six";
	mp['7'] = "seven";
	mp['8'] = "eight";
	mp['9'] = "nine";

	int a, b; cin >> a >> b;

	vector <pair<string, int>> vc;

	for (int i = a; i <= b; i++) {
		string s = to_string(i);
		string tmp = "";
		for (int j = 0; j < s.length(); j++) {
			tmp += mp[s[j]];
		}
		vc.push_back({ tmp,i });
//		cout << tmp << endl;
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++) {
		if (i != 0 && (i % 10 == 0))
			cout << '\n';
		cout << vc[i].second << " ";
	}


}