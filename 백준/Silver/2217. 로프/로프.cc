#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector <int> rope;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		rope.push_back(c);
	}

	sort(rope.begin(), rope.end(), greater<>());

	int max = -1;
	for (int i = 0; i < n; i++) {
		if (i < n && max < rope[i]*(i+1)) {
			max = rope[i] * (i + 1);
		}
	}

	cout << max << endl;



}