#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	vector <int> vc;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		vc.push_back(c);
	}

	sort(vc.begin(), vc.end());

	int cnt = 0;

	for (int i = 0; i < vc.size(); i++) {
		int targetNum = vc[i];
		// targetNum은 제외해야함 -> 이걸 어케 조건을 걸지? ㅇㅅㅇ
		bool exceptNum = false;

		int start = 0, end = vc.size() - 1;

		if (vc[start] == targetNum) {
			start++;
			exceptNum = true;
		}
		else if (vc[end] == targetNum) {
			end--;
			exceptNum = true;
		}
		
		while (start < end) {

			if (!exceptNum) {
				if (vc[start] == targetNum) {
					start++;
					exceptNum = true;
					continue;
				}
				else if (vc[end] == targetNum) {
					end--;
					exceptNum = true;
					continue;
				}
			}

			// 정답이면 끝내기
			if (vc[start] + vc[end] == targetNum) {
				cnt++;
				break;
			}

			// 두 개의 합이 target보다 크다면 오른쪽을 -1
			if (vc[start] + vc[end] > targetNum) {
				end--;
				continue;
			}
			
			// 두 수의 합이 target보다 작다면 왼쪽을 +1
			if (vc[start] + vc[end] < targetNum) {
				start++;
				continue;
			}
		}
	}


	cout << cnt;
}