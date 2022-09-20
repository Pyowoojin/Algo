#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt2d(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void prt1d(const vector <T>& v1) {
	cout << endl;
	for (auto i : v1) {
		cout << i << " ";
	}
}

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else
		return a.first > b.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector <int> tmp;
	vector <vector <int>> vec(n, tmp);

	vector <pair<int, int>> winner;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int c; cin >> c;
			vec[i].push_back(c);
		}
	}

	for (int j = 0; j < n; j++) {
		int max = -9999;
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			for (int k = i + 1; k < 4; k++) {
				for (int l = k + 1; l <5; l++) {
					sum = vec[j][i] + vec[j][k] + vec[j][l];
					sum = sum % 10;
					if (max < sum) {
						max = sum;
					}
				}
			}
			if (max > 8)
				break;
		}
		winner.push_back({ max, j });
	}

	sort(winner.begin(), winner.end(), comp);

	cout << winner[0].second + 1;
	
}