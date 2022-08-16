#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k; cin >> k;
	int arr[10] = { 0, };
	int n;
	vector <int> a;
	for (int i = 0; i < k; i++) {
		string temp = "9990";
		int ten = 10;
		int cnt = 1;
		cin >> n;
		int newN = n;
		while (ten) {
			newN = n * cnt;
			if (newN * cnt == newN * (cnt + 1)) {
				break;
			}
			temp = to_string(newN);
			for (int i = 0; i < temp.size(); i++) {
				if (arr[temp[i] - '0'] == 0) {
					arr[temp[i] - '0'] = 1;
					ten--;
				}
			}
			cnt++;
		}
		a.push_back(stoi(temp));
		fill(arr, arr + 10, 0);
	}

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 9990) {
			cout << "Case #" << i + 1 << ":" << " INSOMNIA\n";
		}
		else
			cout << "Case #" << i + 1 << ": " << a[i] << '\n';
	}
}