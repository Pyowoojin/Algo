#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

char arr[50][50];

int maxN = -1;

void maxCheck(int n) {


	// 가로줄 체크
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != n - 1) {
				int cnt = 1;
				while ((j != n - 1) && (arr[i][j] == arr[i][j + 1])) {
					cnt++;
					j++;
					if (maxN < cnt)
						maxN = cnt;
				}
			}
		}
	}
	
	// 세로줄 체크
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (i != n - 1) {
				int cnt = 1;
				while ((i != n - 1) && (arr[i][j] == arr[i + 1][j])) {
					cnt++;
					i++;
					if (maxN < cnt)
						maxN = cnt;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	// 예제 출력
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 우 -> 좌 교환 (x,n)일 때 제외하고
			if (j + 1 != n) {
				char tmp = arr[i][j];
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = tmp;
				maxCheck(n);
				arr[i][j + 1] = arr[i][j];
				arr[i][j] = tmp;
			}

			// 위 -> 아래 교환 (n, X) 제외하고
			if (i + 1 != n) {
				char tmp = arr[i][j];
				arr[i][j] = arr[i + 1][j];
				arr[i + 1][j] = tmp;
				maxCheck(n);
				arr[i + 1][j] = arr[i][j];
				arr[i][j] = tmp;
			}
		}
	}

	cout << maxN;


}