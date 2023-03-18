#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	long long n; cin >> n;
	vector <long long> vc(n);
	for (long long i = 0; i < n; i++) {
		cin >> vc[i];
	}

	long long targetNum = 0;
	cin >> targetNum;

	long long pairOfNum = 0;

	long long start = 0;
	long long end = vc.size() - 1;
	long long endCount = 1;

	sort(vc.begin(), vc.end());


	while (start < end) {
		if (vc[start] + vc[end] == targetNum) {
			start++;
			pairOfNum++;
		}
		/*if (start == end) {
			endCount++;
			end = vc.size() - endCount;
		}*/

		if (vc[start] + vc[end] > targetNum) {
			end--;
		}

		else if (vc[start] + vc[end] < targetNum) {
			start++;
		}
	}

	cout << pairOfNum;

}
