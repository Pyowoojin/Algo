#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int total = 0;
	int cnt = 0;

	vector <int> vc;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		total += c;
		vc.push_back(c);
	}

	int mean = total / n;

	int whileCnt = n;
	int k = 0;
	while (k < whileCnt) {
		while (vc[k] != mean) {
			// 현재 인덱스가 평균값보다 클 경우, 오른쪽으로 1 전달
			if (vc[k] > mean) {
				int plus = vc[k] - mean;
				vc[k] = mean;
				vc[k + 1] = vc[k + 1] + plus;
				cnt += plus;
			}
			// 현재 인덱스가 평균값보다 작을 경우, 왼쪽으로 1 전달
			// 오른쪽에서 1 받아오기ㅎㅎ
			else {
				int plus = mean - vc[k];
				vc[k] = mean;
				vc[k + 1] = vc[k + 1] - plus;
				cnt += plus;
			}
		}
		k++;
	}

	cout << cnt;


}