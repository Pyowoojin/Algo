#include <bits/stdc++.h>
using namespace std;

int arr[9];

void init() {
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int team, teamMate; cin >> team >> teamMate;
	int total = team * teamMate;
	vector <int> vc;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	sort(vc.begin(), vc.end(), greater<>());
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < vc.size(); i++) {
		sum += vc[i];
		cnt++;
		if (sum >= total)
			break;
	}
	if (sum < total)
		cout << "STRESS";
	else cout << cnt;


}