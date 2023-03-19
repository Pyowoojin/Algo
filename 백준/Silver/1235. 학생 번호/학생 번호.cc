#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector <string> vc(n);
	set <string> s;

	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}
	// 현재 문자열의 길이를 나타냄
	int k = 0;

	// 길이만큼 뒤에서부터 집어넣으면서 같은 숫자가 나오지 않으면 종료
	for (int i = vc[0].length() - 1; i >= 0; i--) {
		k++;
		bool ans = true;
		// 배열 크기 만큼 실행
		for (int j = 0; j < n; j++) {

			string tmp;
			for (int l = vc[0].length() - 1; l > vc[0].length() - k - 1; l--) {
				tmp += vc[j][l];
			}
			string ttmp;
			for (int z = tmp.length() - 1; z > -1; z--) {
				ttmp += tmp[z];
			}

			// cout << tmp << " " << ttmp << endl;

			if (s.find(ttmp) == s.end()) {
				s.insert(ttmp);
			}
			else
			{
				ans = false;
				break;
			}
		}
		if (ans == true)
			break;
	}

	cout << k;
}