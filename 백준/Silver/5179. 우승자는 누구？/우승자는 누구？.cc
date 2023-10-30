#include <bits/stdc++.h>
using namespace std;
struct PS {
	int TryingCount = 0;
	bool IsClear = false;
};

bool comp(pair <pair <int, int>, int> &a, pair <pair <int, int>, int>&b){
	if (a.first.first != b.first.first) {
		return a.first.first > b.first.first;
	}
	return a.first.second < b.first.second;
}

int main() {
	// first-first = 문제수
	// first-second = 점수
	// second = 번호

	int h = 1;
	int tc; cin >> tc;

	while (h <= tc) {
		vector <pair <pair <int, int>, int>> vc(501, { {0, 0}, -1 });
		int m, n, p; cin >> m >> n >> p;
		// 참가자 1번부터 p번까지
		// 점수 저장하는 배열 필요
		// 참가번호 : 문제번호 : 제출 시각 : 정답 여부
		// 문제 번호는 고유함 -> map으로 구현
		vector <map <char, PS>> mp(p + 1);

		for (int i = 0; i < n; i++) {
			int participant;
			char question;
			int submitTime;
			bool success;
			cin >> participant >> question >> submitTime >> success;

			// 해당 참가자가 문제를 시도했었다면
			if (mp[participant].find(question) != mp[participant].end()) {
				// 기존에 이미 해결한 문제인지 확인
				if (mp[participant][question].IsClear == false) {
					mp[participant][question].TryingCount += 1;
					mp[participant][question].IsClear = success;
					// 문제를 최초로 해결했으면 점수를 계산한다.
					if (success) {
						// first = 문제수, second = 점수
						vc[participant].first.first += 1;
						vc[participant].first.second += (mp[participant][question].TryingCount - 1) * 20 + submitTime;
					}
				}
			}
			// 시도하지 않았던 문제라면
			else {
				// 해결했다면
				PS tempPS;
				if (success) {
					// 성공했다면 문제 수만 늘려준다
					vc[participant].first.first += 1;
					vc[participant].first.second += submitTime;
				}
				tempPS.IsClear = success;
				tempPS.TryingCount = 1;
				vc[participant].second = participant;
				mp[participant].insert({ question, tempPS });
			}
		}

		sort(vc.begin(), vc.end(), comp);

		cout << "Data Set " << h << ":" << endl;

		for (int i = 0; i < vc.size(); i++) {
			if (vc[i].second != -1) {
				cout << vc[i].second << " " << vc[i].first.first << " " << vc[i].first.second << '\n';
			}
		}
		h++;
		cout << endl;
	}
}