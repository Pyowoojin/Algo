#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int score; cin >> score; int p; cin >> p;

	vector <int> ranking;

	int rank = 1;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		ranking.push_back(c);
	}

	for (int k = 0; k < ranking.size(); k++) {
		if (score < ranking[k]){
			rank++;
		}
		if (score == ranking[k]) {
			rank = k + 1;
			break;
		}
	}

	if (rank == p) {
		if (score == ranking[p - 1]) {
			rank = -1;
		}
	}

	if ( n > 0 && (score == ranking[ranking.size()-1])) {
		if (n >= p) {
			rank = -1;
		}
	}

	if (rank > p)
		rank = -1;
	
	cout << rank;

}