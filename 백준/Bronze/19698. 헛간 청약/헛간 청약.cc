#include <bits/stdc++.h>
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


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, w, h, l; cin >> n >> w >> h >> l;
	int size = w * h;

	int minN = min(w, h);
	int maxN = max(w, h);

	minN = minN / l;
	maxN = maxN / l;
	int total = minN * maxN;

	if (total > n)
		total = n;
	cout << total;
}