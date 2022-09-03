#include <bits/stdc++.h>
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	while (n) {

		deque <pair <int, int>> pq;
		deque <int> priority;

		int theNumbOfpaper, wonder;
		cin >> theNumbOfpaper >> wonder;

		for (int i = 0; i < theNumbOfpaper; i++) {
			int c;  cin >> c;
			if (wonder == i) {
				pq.push_back({ c, 0 });
			}
			else
				pq.push_back({ c, 9999 });

			priority.push_back(c);
		}

		sort(priority.begin(), priority.end(), greater<>());

		int cnt = 0;
		int ans = -999;

		while (!pq.empty()) {
			if (priority.front() == pq.front().first) {
				cnt++;
				if (pq.front().second == 0) {
					ans = cnt;
					break;
				}
				priority.pop_front();
				pq.pop_front();
			}

			else if (priority.front() != pq.front().second) {
				auto tmp = pq.front();
				pq.pop_front();
				pq.push_back(tmp);
			}
		}

		cout << ans << endl;
		n--;
	}

}