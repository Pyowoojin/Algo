#include <bits/stdc++.h>
using namespace std;

long long dfs(long long n) {
	if (n <= 1)
		return 1;
	else
		return n * dfs(n - 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	cout << dfs(n);

}