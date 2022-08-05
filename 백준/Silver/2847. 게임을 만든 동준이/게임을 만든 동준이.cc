#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector <int> round;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		round.push_back(temp);
	}

	int i = round.size() - 1;
	while (i > 0) {
		if (i > 0) {
			if (round[i] <= round[i - 1] ) {
				round[i - 1] -= 1;
				count++;
				i++;
			}
		}
		i--;
	}

	cout << count;
}