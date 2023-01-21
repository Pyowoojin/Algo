#include <bits/stdc++.h>
using namespace std;

void prt(vector <vector <int>>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++)
			cout << vc[i][j] << "";
		cout << '\n';
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 1;
	int totalcnt = 0;
	int bird; cin >> bird;


	while (1) {
		if (bird == 0)
			break;


		if (cnt > bird) {
			cnt = 1;
			continue;
		}

		bird -= cnt;
		totalcnt++;
		cnt++;

	}
	
	cout << totalcnt;

}