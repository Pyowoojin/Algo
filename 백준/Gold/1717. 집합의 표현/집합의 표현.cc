#include <bits/stdc++.h>
using namespace std;

int Find_root(int x, int arr[]) {
	if (x == arr[x]) {
		return x;
	}
	else {
		return arr[x] = Find_root(arr[x], arr);
	}
}

void Union_merge(int x, int y, int arr[]) {
	x = Find_root(x, arr);
	y = Find_root(y, arr);

	// 속한 집합의 루트가 다르다면
	if (x != y) {
		arr[x] = y;
	}
}

bool IsUnion(int a, int b, int arr[]) {
	int x = Find_root(a, arr);
	int y = Find_root(b, arr);

	if (x == y)
		return true;
	else
		return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; cin >> n >> m;
	// 0 a b -> a와 b의 집합을 합친다
	// 1 a b -> a와 b가 같은 집합에 있나?

	int* arr = new int[n + 1];

	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	while (m) {
		int command, a, b; cin >> command >> a >> b;

		if (command == 0) {
			Union_merge(a, b, arr);
		}
		else if (command == 1) {
			if (IsUnion(a, b, arr)) {
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}

		m--;
	}

}