#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	long long n, m, k; cin >> n >> m >> k;

	vector <long long> originStorage;
	vector <long long> newStorage;
	long long totalCost = 0;

	long long originCnt = 0, newCnt = 0;

	for (long long i = 0; i < n; i++) {
		long long c; cin >> c;
		originStorage.push_back(c);
		originCnt += c;
	}

	for (long long i = 0; i < m; i++) {
		long long c; cin >> c;
		newStorage.push_back(c);
		newCnt += c;
	}

	long long totalCnt = 0;

	long long originCurFloor = 0, newCurFloor = 0;
	while (originCnt && newCnt) {
		// 해당 층에 물건이 없으면 다음 층으로
		if (!originStorage[originCurFloor]) {
			originCurFloor++;
			continue;
		}
		// 해당 층에 공간이 없으면 다음 층으로
		if (!newStorage[newCurFloor]) {
			newCurFloor++;
			continue;
		}

		totalCnt++;
		totalCost += originCurFloor + 2 + newCurFloor;
		originStorage[originCurFloor]--;
		newStorage[newCurFloor]--;
		originCnt--; newCnt--;

	}
	cout << totalCnt << " " << totalCost;

}