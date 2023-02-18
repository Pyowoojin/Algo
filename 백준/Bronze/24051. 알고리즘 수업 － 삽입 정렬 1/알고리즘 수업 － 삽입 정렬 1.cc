#include <bits/stdc++.h>
using namespace std;

int insertion_sort(int arr[], int k, int maxN) {
	int ans = -1;
	int countT = 0;

	for (int i = 1; i < maxN; i++) {
		int location = i - 1;
		int newItem = arr[i];

		while (0 <= location && newItem < arr[location]) {
			countT++;

			if (k == countT)
				ans = arr[location];

			arr[location + 1] = arr[location];
			location--;
		}

		if (location + 1 != i) {
			countT++;
			if (k == countT)
				ans = arr[location];
			arr[location + 1] = newItem;
		}

	}

	return ans;
}

int main() {
	int n, k; cin >> n >> k;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr[i] = c;
	}

	cout << insertion_sort(arr, k, n);
}