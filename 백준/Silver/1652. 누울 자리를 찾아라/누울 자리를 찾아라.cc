#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector <vector <char>> vc(n, vector <char>(n));
	vector <vector <char>> visited(vc);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			vc[i][j] = s[j];
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << vc[i][j];
		cout << endl;
	}*/

	int horizonCnt = 0;
	int verticalCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vc[i][j] == '.') {
				if (j + 1 < n && vc[i][j+1] == '.') {
					int k = j;
					while (k < n && vc[i][k] != 'X') {
						j++;
						k++;
					}
					horizonCnt++;
				}
			}
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (vc[i][j] == '.') {
				if (i + 1 < n && vc[i+1][j] == '.') {
					int k = i;
					while (k < n && vc[k][j] != 'X') {
						i++;
						k++;
					}
					verticalCnt++;
				}
			}
		}
	}

	cout << horizonCnt << " " << verticalCnt;

}

