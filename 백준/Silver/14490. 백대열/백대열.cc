#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

int gcd(int n, int m) {
	if (m == 0)
		return n;
	return gcd(m, n % m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	string one = "", two = "";
	
	int n = 0, m = 0;

	int i = 0;
	while (s[i] != ':') {
		one += s[i];
		i++;
	}
	i++;
	while (i < s.length()) {
		two += s[i];
		i++;
	}

	int p = gcd(max(stoi(one), stoi(two)), min(stoi(one), stoi(two)));

	cout << (stoi(one)) / p << ":" << (stoi(two)) / p;


}