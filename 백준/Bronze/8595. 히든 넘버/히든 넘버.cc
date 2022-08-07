#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	string s; cin >> s;

	// 오버플로우를 막기 위해 ull 형으로 처리
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		// 숫자가 나올 경우 while문 진입.
		if (s[i] - '0' < 10) {
			string temp = "";
			// 두 자리 수 이상을 숫자로 바꿔주기 위해 string으로 넣어줌
			// [ex) abc17abc -> 1과 7이 아닌 17로 인식하기 위해]
			while (s[i] - '0' < 10 && i < n) {
				temp += s[i];
                // 다음 인덱스로 넘어감
				i++;
			}
			// 숫자가 6자리 이상이 된다면 히든넘버에서 제외합니다.
			if (temp.length() > 6)
				temp = "0";
			// 최종값에 더해줌
			sum += stoll(temp);
		}
	}
	// 히든넘버가 없으면 0 출력
	if (sum == 0)
		cout << "0";
	else
		cout << sum;
}