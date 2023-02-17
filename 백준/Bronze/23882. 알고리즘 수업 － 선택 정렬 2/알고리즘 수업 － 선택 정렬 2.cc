#include <bits/stdc++.h>
using namespace std;

int totalCount = 0;
vector <int> ans;

void swapp(int arr[], int a, int b, int k, int arrSize) {
	totalCount++;

	// cout << arr[a] << ", " << arr[b] << endl;

	int tmp = arr[b];
	arr[b] = arr[a];
	arr[a] = tmp;

	if (totalCount == k) {
		//cout << " k : " << k << endl;
		for (int i = 0; i < arrSize; i++) {
			ans.push_back(arr[i]);
		}
	}
}

void selection_sort(int arr[], int arrSize, int k) {
	for (int i = arrSize - 1; i > 0; i--) {
		int maxN = i;
		for (int j = i - 1; j > -1; j--) {
			if (arr[maxN] < arr[j])
				maxN = j;
		}
		// cout << i << " 번 loop의 maxN : " << maxN << endl;
		if (maxN != i) {
			swapp(arr, maxN, i, k, arrSize);
		}
		// cout << i << "번 정렬 : ";
		
		/*for (auto i = 0; i < arrSize; i++)
			cout << arr[i] << " ";
		cout << endl;*/
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int arrSize, swapCount;
	cin >> arrSize >> swapCount;

	int *arr = new int[arrSize];

	for (int i = 0; i < arrSize; i++) {
		int c; cin >> c;
		arr[i] = c;
	}

	selection_sort(arr, arrSize, swapCount);

	if (ans.size() != 0) {
		for (auto i : ans)
			cout << i << " ";
	}
	else
		cout << "-1";
}