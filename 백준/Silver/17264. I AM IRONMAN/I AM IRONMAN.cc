#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int totalRound, playerNum; cin >> totalRound >> playerNum;
	int winRate, loseRate, goal; cin >> winRate >> loseRate >> goal;
	loseRate = -loseRate;

	vector <pair<string, int>> tmp;

	for (int i = 0; i < playerNum; i++) {
		string s; cin >> s; string lw; cin >> lw;
		if (lw == "W") {
			tmp.push_back({ s, winRate });
		}
		else if (lw == "L") {
			tmp.push_back({ s, loseRate });
		}
	}
	/*for (auto i : tmp)
		cout << i.first << " 213213   " << i.second << endl;*/

	int myRating = 0;
	string ans = "I AM IRONMAN!!";

	for (int i = 0; i < totalRound; i++) {
		string s; cin >> s;
		auto it = find_if(tmp.begin(), tmp.end(), [&s](const pair<string, int>& ele) { return ele.first == s; });
		if (it != tmp.end()) {
			if (myRating + (*it).second < 0)
				myRating = 0;
			else
				myRating += (*it).second;
		}
		else {
			if (myRating + loseRate < 0)
				myRating = 0;
			else
				myRating += loseRate;
		}
		if (myRating >= goal)
			ans = "I AM NOT IRONMAN!!";
	}

	cout << ans;


}