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
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end; cin >> start >> end;
	/*bool* visit = new bool[end + 1];
	fiint(visit, visit + end + 1, 0);*/

	int cnt = 0;

	queue <pair<long long, long long>> q;
	pair <long long, long long> tmp;
	q.push({ start, 0 });
	
	bool flag = false;

	while (!q.empty()) {
		tmp = q.front(); q.pop();
		long long now = tmp.first;
		if (now == end) {
			cout << tmp.second+1;
			flag = true;
			break;
		}
		long long next1 = now * 2;
		long long next2 = now * 10 + 1;

		if (next1 <= end)
			q.push({ next1, tmp.second + 1 });
		if (next2 <= end)
			q.push({ next2, tmp.second + 1 });
	}

	if (flag == false)
		cout << "-1";

}