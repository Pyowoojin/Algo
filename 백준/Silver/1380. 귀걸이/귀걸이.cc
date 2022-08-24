#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sceneCnt = 1;
	while (1) {
		int n; cin >> n;
		cin.ignore();
		if (n == 0)
			break;

		vector <string> li;
		for (int i = 0; i < n; i++) {
			string s; getline(cin, s);
			li.push_back(s);
		}

		for (int i = 0; i < n * 2 - 1; i++) {
			int c; cin >> c;
			char cha; cin >> cha;

			if (cha) {
				arr[c - 1] += 1;
			}
		}

		for (int i = 0; i < n; i++) {
			if (arr[i] == 1)
				cout << sceneCnt << " " << li[i] << endl;
		}

		fill(arr, arr + 101, 0);
		li.clear();
		sceneCnt++;
	}
}