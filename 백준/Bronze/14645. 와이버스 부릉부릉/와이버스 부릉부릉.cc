#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0, 1, 0, -1 };

int arr[100];

struct player {
	int a;
	int b;
	int c;
};

void init() {
	for (int i = 0; i < 100; i++)
		arr[i] = 0;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int c; cin >> c;
		}
	}

	cout << "비와이";

}