#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	vector <int> a, b;
	unordered_map <int, int> ls1, ls2;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		ls1.insert({t, i % 1000});
		a.push_back(t);
	}
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		ls2.insert({ t, i % 1000 });
		b.push_back(t);
	}
	int ls1CNT = ls1.size();
	int ls2CNT = ls2.size();
	
	for (auto& i : ls1) {
		if (ls2.find(i.first) != ls2.end())
			ls1CNT--;
	}
	for (auto& i : ls2) {
		if (ls1.find(i.first) != ls1.end())
			ls2CNT--;
	}
	cout << ls1CNT + ls2CNT;
}