#include <bits/stdc++.h>
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
int arr[9];

void out() {
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void init() {
	for (int i = 0; i < 9; i++) {
		arr[i] = arr[i] + 1;
	}
	arr[6] += 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;

	int ans = 1;

	init();

	for (int i = 0; i < s.length(); i++) {
		int n; n = s[i] - '0';

		if (n == 9) {
			n = 6;
		}

		if (arr[n] > 0) {
			arr[n] = arr[n] - 1;
		}
		else if (arr[n] == 0) {
			ans++;
			init();
			arr[n] = arr[n] - 1;
		}
	}

	cout << ans;

}