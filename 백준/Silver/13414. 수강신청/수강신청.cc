#include <bits/stdc++.h>
#include <map>
using namespace std;

bool cmp(const pair <string, int>& a, const pair <string, int>& b) {
	return a.second < b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map <string, int> mpp;
	int k, l; cin >> k >> l;

	for (int i = 0; i < l; i++) {
		string s; cin >> s;
		// 중복 신청이 아닐 경우
		if(mpp.find(s) == mpp.end()){
			mpp.insert({ s, i });
		}
		else {
			mpp[s] = i;
		}
	}

	vector <pair <string, int>> vc(mpp.begin(), mpp.end());
	sort(vc.begin(), vc.end(), cmp);

	int z = 0;
	while (z < vc.size() && z < k) {
		cout << vc[z].first << "\n";
		z++;
	}
}