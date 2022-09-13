#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	
	vector <int> vc;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	int left = 1;
	int maxN = vc[0];
	
	for (int i = 0; i < n; i++) {
		if (maxN < vc[i]) {
			maxN = vc[i];
			left++;
		}
	}

	int right = 1;

	reverse(vc.begin(), vc.end());
	maxN = vc[0];

	for (int i = 0; i < n; i++){
		if (maxN < vc[i]) {
			maxN = vc[i];
			right++;
		}
	}

	cout << left << '\n' << right;

}