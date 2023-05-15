#include <bits/stdc++.h>
using namespace std;

bool arr[100001];

int main() {
	int n, k; cin >> n >> k;
	queue <pair <int,int>> q;
	vector <int> vc;

	q.push({ n, 0 });
	arr[n] = true;
	int cnt = 1;

	while (!q.empty()) {

		int nowX = q.front().first;
		int nowCost = q.front().second;

		if (nowX == k) {
			vc.push_back(nowCost);
			arr[nowX] = false;
		}

		q.pop();
		arr[nowX] = true;
		
		if (nowX + 1 <= 100000 && !arr[nowX + 1]) {
			q.push({ nowX + 1, nowCost + 1 });
			
		}
		
		if (nowX - 1 > -1 && !arr[nowX - 1]) {
			q.push({ nowX - 1, nowCost + 1 });
		}

		if (nowX * 2 <= 100000 && !arr[nowX * 2]) {
			q.push({ nowX * 2, nowCost + 1 });
			
		}
	}

	for (int i = 1; i < vc.size(); i++) {
		if (vc[0] != vc[i]) {
			break;
		}
		else {
			cnt++;
		}
	}

	cout << vc[0] << '\n' << cnt;

}