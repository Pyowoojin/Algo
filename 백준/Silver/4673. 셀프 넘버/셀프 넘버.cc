#include <bits/stdc++.h>
using namespace std;

int selfNum[10001];

void sn(int n) {
	string strN = to_string(n);
	int len = strN.size();
	int sum = n;
	for (int i = 0; i < len; i++) {
		sum += strN[i] - '0';
	}
	if (selfNum[sum] == 0 && sum < 10001)
		selfNum[sum] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 10001; i++) {
		sn(i);
	}

	for (int i = 1; i <= 10000; i++) {
		if (selfNum[i] == 0) {
			cout << i << endl;
		}
	}


}