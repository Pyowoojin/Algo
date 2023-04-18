#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int, int>& a, pair <int, int>& b) {
	if (a.first != b.first) {
		return a.first > b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {

	int n; cin >> n;
	vector <pair <int, int>> vc(n);

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		vc[i].first = a; vc[i].second = b;
	}

	sort(vc.begin(), vc.end(), comp);

	int flag = vc[4].first;
	int ansCnt = 0;

	for (int i = 5; i < n; i++) {
		if (flag == vc[i].first) {
			ansCnt++;
		}
		else
			break;
	}

	cout << ansCnt;

}