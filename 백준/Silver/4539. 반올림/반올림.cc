#include <bits/stdc++.h>
using namespace std;

int ban(int n) {
	string t = to_string(n);
	int size = t.length();

	if (size == 1)
		return n;
	else {
		for (int i = size-1; i > 0; i--) {
			// 10의 자리 이상일 때 마지막 자리부터 반올림 수행
			if ((t[i] - '0') > 4) {
				if (i == 1 && t[i-1] == '9') {
					t[i - 1] = '1';
					t += '0';
				}
				// 해당 자리가 5 이상일 경우 다음 자리에 1을 더해준다.
				else {
					int b = (t[i - 1] - '0') + 1;
					t[i - 1] = char(b + '0');
				}
			}
			t[i] = '0';
		}
		return stoi(t);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		arr.push_back(ban(temp));
	}

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

}