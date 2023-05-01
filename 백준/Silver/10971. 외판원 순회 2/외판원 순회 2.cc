#include <bits/stdc++.h>
using namespace std;

int minimum = 0x7fffffff;
int n;

vector <bool> visited;
vector <int> ans;

void Backtracking(int start, vector <vector <int>> &vc, int depth, int nowCost, int originStart) {
	// n+1번 돌면 (모든 노드를 돌고 최초 노드로 돌아오면 종료)
	if (depth == n+1) {
		if (nowCost < minimum) {
			minimum = nowCost;
			/*for (auto i : ans)
				cout << i << " ";
			cout << originStart << endl;*/
		}
		return;
	}
	if (depth == n && vc[start][originStart] != 0) {
		nowCost += vc[start][originStart];
		Backtracking(start, vc, depth + 1, nowCost, originStart);
	}

	// 모든 노드를 돌 것임
	for (int i = 0; i < n; i++) {

		// 마지막 노드가 아닌데 
		if (depth+1 != n+1) {
			// 출발 노드로 진입하려 할 때는 continue
			if (i == originStart)
				continue;
		}
		// 방문 안 한 노드만 들어갈거임. 길이 있는 노드만 들어갈거임
		if (visited[i] == false && vc[start][i] != 0) {
			visited[i] = true;
			ans.push_back(i);
			nowCost += vc[start][i];
			Backtracking(i, vc, depth + 1, nowCost, originStart);
			ans.pop_back();
			nowCost -= vc[start][i];
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	// 입력부
	cin >> n;
	for (int i = 0; i < n; i++) {
		visited.push_back(false);
	}

	vector <int> vc(n);
	vector <vector <int>> arr(n, vc);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 0번부터 n번까지 다 실행해볼거임
	for (int i = 0; i < n; i++) {
		int start = i;
		ans.push_back(start);
		for (int i = 0; i < n; i++) {
			visited.push_back(false);
		}
		Backtracking(start, arr, 1, 0, start);
		ans.pop_back();
	}

	cout << minimum;
}