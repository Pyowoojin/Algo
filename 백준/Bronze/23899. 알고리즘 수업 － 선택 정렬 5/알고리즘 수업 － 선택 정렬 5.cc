#include <bits/stdc++.h>
using namespace std;

int ansBool = false;

void swapp(int arr[], int a, int b, int arrSize) {
	int tmp = arr[b];
	arr[b] = arr[a];
	arr[a] = tmp;
}

bool comp(int arr[], int arr2[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

void selection_sort(int arr[], int arrSize, int k, int arr2[]) {
	for (int i = arrSize - 1; i > 0; i--) {
		int maxN = i;
		for (int j = i - 1; j > -1; j--) {
			if (arr[maxN] < arr[j])
				maxN = j;
		}
		if (maxN != i) {
			swapp(arr, maxN, i, k);
		}
		ansBool = comp(arr, arr2, arrSize);
		if (ansBool)
			break;

	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int arrSize, swapCount = 1;
	cin >> arrSize;

	int *arr = new int[arrSize];
	int* arr2 = new int[arrSize];

	for (int i = 0; i < arrSize; i++) {
		int c; cin >> c;
		arr[i] = c;
	}
	for (int i = 0; i < arrSize; i++) {
		int c; cin >> c;
		arr2[i] = c;
	}

	if (!comp(arr, arr2, arrSize)) {
		selection_sort(arr, arrSize, swapCount, arr2);
		if (ansBool)
			cout << "1";
		else
			cout << "0";
	}
	else
		cout << "1";
}