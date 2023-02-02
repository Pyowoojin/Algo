#include <bits/stdc++.h>
using namespace std;

int WriteNum(int start, int end, int targetNum) {
	// string에 저장없이 쭉 쓰다가 k번째 자리가 나오면 그거 출력하고 그냥 끝내기
	int nowNum = 0;
	int ans = -1;
	while (start <= end) {
		// 지금 더하는 숫자가 targetNum을 지나친다면 해당 숫자 추적 후 출력
		string nowNumStr = to_string(start);

		nowNum += nowNumStr.size();

		if (nowNum >= targetNum) {
			int tmp = nowNum - nowNumStr.size();
			ans = nowNumStr[targetNum - tmp - 1] - '0';

			break;
		}
		start++;
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k; cin >> n >> k;

	// 메모리 초과 해결 방법
	cout << WriteNum(1, n, k);
}