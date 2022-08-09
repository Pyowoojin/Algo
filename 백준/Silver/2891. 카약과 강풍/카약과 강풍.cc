#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int teamCnt, disabled, surplus;
	cin >> teamCnt >> disabled >> surplus;
	
	int* team = new int[teamCnt];
	fill(team, team + teamCnt, 0);

	for (int i = 0; i < disabled; i++) {
		int t; cin >> t;
		team[t - 1] -= 1;
	}
	for (int i = 0; i < surplus; i++) {
		int t; cin >> t;
		team[t - 1] += 1;
	}


	/*cout << endl;

	for (int i = 0; i < teamCnt; i++) {
		cout << team[i] << " ";
	}

	cout << endl;*/

	for (int i = 0; i < teamCnt; i++) {
		if (i == 0) {
			if (team[i + 1] == -1 && team[i] == 1) {
				team[i]--;
				team[i + 1]++;
			}
			continue;
		}
		if (i + 1 == teamCnt) {
			if (team[i - 1] == -1 && team[i] == 1) {
				team[i]--;
				team[i - 1]++;
			}
			continue;
		}

		if ((team[i - 1] == -1 || team[i + 1] == -1) && team[i] == 1) {
			team[i]--;
			if (team[i - 1] == -1) {
				team[i - 1]++;
				continue;
			}
			else if (team[i + 1] == -1) {
				team[i + 1]++;
				continue;
			}
		}
		
	}

	int cnt = 0;
	for (int i = 0; i < teamCnt; i++) {
		if (team[i] == -1)
			cnt++;
	}

	cout << cnt;

}