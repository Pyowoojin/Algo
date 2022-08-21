#include <bits/stdc++.h>
using namespace std;

void opt(int arr[]) {
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int chk(int arr[]) {
	for (int i = 0; i < 5; i++) {
		if (arr[i] != i + 1)
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[5] = { 0, };

	for (int i = 0; i < 5; i++) {
		int n; cin >> n;
		arr[i] = n;
	}
	for (int i = 0; i < 4; i++) {
		if (arr[i] > arr[i + 1]) {
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			opt(arr);
		}
		
		if (i == 3) {
			if (!chk(arr))
				i = -1;
		}
	}

}