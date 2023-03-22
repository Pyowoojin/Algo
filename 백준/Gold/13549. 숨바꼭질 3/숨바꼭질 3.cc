#include <bits/stdc++.h>
using namespace std;

bool visited[200001];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int start, end;
	cin >> start >> end;

	queue <pair <int, int>> q;

	q.push({ start, 0 });

	pair <int, int> tmp;

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		if (tmp.first == end) {
			cout << tmp.second;
			break;
		}

		int next = tmp.first * 2;
		if (next < 200001 && !visited[next]) {
			visited[next] = true;
			q.push({ next, tmp.second });
		}

		next = tmp.first - 1;
		if (next >= 0 && !visited[next]) {
			visited[next] = true;
			q.push({ next, tmp.second + 1 });
		}

		next = tmp.first + 1;
		if (next < 100001 && !visited[next]) {
			visited[next] = true;
			q.push({ next, tmp.second + 1 });
		}

	}

}