#include <bits/stdc++.h>
using namespace std;

int WriteNum(int start, int end, int targetNum) {
	// string에 저장없이 쭉 쓰다가 k번째 자리가 나오면 그거 출력하고 그냥 끝내기
	int nowNumLen = 0;
	int ans = -1;
	while (start <= end) {
		string nowNumStr = to_string(start);

		nowNumLen += nowNumStr.size();
		if (nowNumLen >= targetNum) {
			int tmp = nowNumLen - nowNumStr.size();
			ans = nowNumStr[targetNum - tmp - 1] - '0';

			break;
		}
		start++;
	}
	return ans;
}

int main() {
	int n, k; cin >> n >> k;
    
	cout << WriteNum(1, n, k);
}