#include <bits/stdc++.h>
using namespace std;

bool ans = true;

void insertion_sort(int arr[], int k, int maxN) {
	int countT = 0;

	for (int i = 1; i < maxN; i++) {
		int location = i - 1;
		int newItem = arr[i];

		while (0 <= location && newItem < arr[location]) {
			countT++;

			arr[location + 1] = arr[location];
			
			if (k == countT)
				return;

			location--;
		}

		if (location + 1 != i) {
			countT++;
			arr[location + 1] = newItem;
			if (k == countT)
				return;
		}

	}
	ans = false;
}

int main() {
	int n, k; cin >> n >> k;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr[i] = c;
	}

	insertion_sort(arr, k, n);

	if (ans) {
		for (auto i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	else
		cout << "-1";
}