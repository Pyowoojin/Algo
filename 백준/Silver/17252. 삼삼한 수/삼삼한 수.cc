#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

long long arr[21];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	if (n == 0)
		cout << "NO";
	else {
		arr[0] = 1;
		arr[1] = 3;

		for (int i = 2; i <= 20; i++) {
			arr[i] = arr[i - 1] * 3;
		} // 1 ~  3486784401까지 저장됨

		int target = n;
		int start = 0;
		for (int i = 0; i < 21; i++) {
			if (target <= arr[i]) {
				start = i;
				break;
			}
		}

		//	cout << start << endl;

		if (arr[start] == target) {
			cout << "YES";
		}

		else {
			start--;
			while (target >= 0 && start > -1) {
				if (target - arr[start] >= 0) {
					// cout << arr[start] << endl;
					target = target - arr[start];
				}
				start--;
				if (target == 0)
					break;
			}
			if (target == 0)
				cout << "YES";
			else
				cout << "NO";
		}
	}
}