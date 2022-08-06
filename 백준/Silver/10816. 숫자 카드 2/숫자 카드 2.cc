#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n;
	unordered_map <int, int> a;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		a[t]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		if (a.find(t) != a.end())
			cout << a[t];
		else
			cout << "0";
		cout << " ";
	}
}