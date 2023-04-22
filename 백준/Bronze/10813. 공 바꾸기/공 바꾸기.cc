#include <bits/stdc++.h>
using namespace std;

void swap(int  a, int b, int arr[]) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int main() {
	int n, m; cin >> n >> m;

	int* arr = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		swap(a, b, arr);
	}

	for (auto i = 1; i <= n; i++)
		cout << arr[i] << " ";
}