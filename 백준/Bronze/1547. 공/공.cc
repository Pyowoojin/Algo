#include <bits/stdc++.h>
using namespace std;

int arr[3] = { 1,0,0 };

void swapp(int a, int b) {
	int tmp = arr[a - 1];
	arr[a - 1] = arr[b - 1];
	arr[b - 1] = tmp;
}


int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		swapp(a, b);
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i] == 1)
			cout << i + 1;
	}
}