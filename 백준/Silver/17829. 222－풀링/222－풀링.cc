#include <bits/stdc++.h>
using namespace std;

int DnC(vector <vector <int>> &arr, int start, int end, int nowSize) {
	vector <int> ans;
	// 현재 사이즈가 2x2 배열이 되었다면 2번째 값 return
	if (nowSize == 2) {
		vector <int> tmp;
		for (int i = start; i < start+2; i++) {
			for (int j = end; j < end+2; j++) {
				tmp.push_back(arr[i][j]);
			}
		}
		sort(tmp.begin(), tmp.end(), greater<>());

		return tmp[1];
	}

	int nS = nowSize / 2;

	// 좌상
	ans.push_back(DnC(arr, start, end, nS));
	// 우상
	ans.push_back(DnC(arr, start, end + nS, nS));
	// 좌하 
	ans.push_back(DnC(arr, start+nS, end, nS));
	// 우하
	ans.push_back(DnC(arr, start + nS, end + nS, nS));

	sort(ans.begin(), ans.end(), greater<>());

	return ans[1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector <vector <int>> vc(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vc[i][j];
		}
	}

	cout << DnC(vc, 0, 0, n);

}

