#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int score, time, totalScore = 0;
	stack <pair<int, int>> st;
	pair <int, int> change;
	for (int i = 0; i < n; i++) {
		int f; cin >> f;
		if (f == 1) {
			cin >> score >> time;
			time--;
			st.push({ score,time });
		}

		if (!st.empty()) {
			if (f == 0) {
				change = st.top();
				st.pop();
				change.second -= 1;
				st.push({ change.first, change.second });

			}

			change = st.top();
			if (change.second == 0) {
				totalScore += change.first;
				st.pop();
			}
		}


	}

	cout << totalScore;


}