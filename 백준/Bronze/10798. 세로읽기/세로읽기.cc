#include <bits/stdc++.h>
using namespace std;

void init(vector <vector<char>> &vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			vc[i][j] = '.';
		}
	}

}

int main() {
	vector <vector <char>> vc(5, vector<char>(15));
	
	string ans;

	init(vc);

	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j];
		}
	}
    
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (vc[j][i] != '.')
				ans += vc[j][i];
		}
	}

	cout << ans;
}