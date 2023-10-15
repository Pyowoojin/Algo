#include <bits/stdc++.h>
using namespace std;

int n, remainedTime;
vector <int> arr;
vector <int> store;
int maxNum = 0;

void SnowMan(int remain, int nowLoc, int curSize) {
	if (remain == 0 || nowLoc >= int(arr.size())) {
		return;
	}
	if(nowLoc > -1)
		curSize += arr[nowLoc];

	if (curSize > maxNum)
		maxNum = curSize;

	for (int i = 1; i <= 2; i++) {
		if (i == 1) {
			SnowMan(remain - 1, nowLoc + 1, curSize);
		}
		else {
			SnowMan(remain - 1, nowLoc + 2, curSize / 2);
		}
	}

}

int main() {
	cin >> n >> remainedTime;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		arr.push_back(c);
	}

	SnowMan(remainedTime + 1, -1, 1);

	cout << maxNum;
}