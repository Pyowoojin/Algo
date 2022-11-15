#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	bool arr[10001] = { false, };
	arr[0] = arr[1] = true;

    // 에라토스테네스의 체
	for (int i = 2; i*i <= 10000; i++) {
		if (!arr[i]) {
			for (int j = i + i; j <= 10000; j += i) {
				arr[j] = true;
			}
		}
	}

	vector <int> vc;

    // 투포인터를 위해 벡터에 값 할당
	for (int i = 0; i <= 10000; i++) {
		if (!arr[i])
			vc.push_back(i);
	}
    
	for (int i = 0; i < tc; i++) {
		int c; cin >> c;

		// 투 포인터
		int start = 0, end = start;
		while (start < vc.size()) {
			int tmp = vc[start] + vc[end];

            // 10 = 5 + 5 같은 숫자로 이루어질 수 있음. 즉, start == end까지 허용
			if (start > end) {
				start = 0;
				end++;
				continue;
			}

			// 정답일 경우
			if(tmp == c){
				cout << vc[start] << " " << vc[end] << '\n';
				break;
			}

			else if (tmp < c)
				start++;
            
            else {
				start = 0;
				end++;
			}
		}
	}
}