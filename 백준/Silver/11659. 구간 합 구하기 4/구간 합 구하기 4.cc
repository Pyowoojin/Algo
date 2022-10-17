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

	int n, m; cin >> n >> m;
	vector <int> vc;
	int* arr = new int[n + 1];
	fill(arr, arr + n + 1, 0);

	int tot = 0;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		tot += c;
		arr[i] += tot;
	}

	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		int end = arr[e - 1], start = arr[s - 2];
		if (s - 2 < 0)
			cout << arr[e - 1] << '\n';
		else
			cout << arr[e - 1] - arr[s - 2] << '\n';
	}

}