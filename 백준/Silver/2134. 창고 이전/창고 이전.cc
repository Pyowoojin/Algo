#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	long long n, m, k; cin >> n >> m >> k;

	vector <long long> origin;
	vector <long long> next;
	long long totalCost = 0;

	long long originCnt = 0, nextCnt = 0;

	for (long long i = 0; i < n; i++) {
		long long c; cin >> c;
		origin.push_back(c);
		originCnt += c;
	}

	for (long long i = 0; i < m; i++) {
		long long c; cin >> c;
		next.push_back(c);
		nextCnt += c;
	}

	long long totalrotn = 0;

	long long originFloor = 0, nextFloor = 0;
	while (originCnt && nextCnt) {
		// 해당 층에 물건이 없으면 다음 층으로
		if (!origin[originFloor]) {
			originFloor++;
			continue;
		}
		// 해당 층에 공간이 없으면 다음 층으로
		if (!next[nextFloor]) {
			nextFloor++;
			continue;
		}

		totalrotn++;
		totalCost += originFloor + 2 + nextFloor;
		origin[originFloor]--;
		next[nextFloor]--;
		originCnt--; nextCnt--;

	}
	cout << totalrotn << " " << totalCost;

}