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
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << endl;
	}

}