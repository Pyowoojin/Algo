#include <bits/stdc++.h>
#define ll long long
using namespace std;

void swapStr(string& str) {
	char tmp = str[0];
	str.erase(0, 1);
	str += tmp;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	set <string> st;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		// 해시 테이블에 현재 값이 없다면 원형 큐처럼 돌며 모든 문자열을 넣을 것임
		if (st.find(s) == st.end()) {
			st.insert(s);
			for (int k = 1; k < s.length(); k++) {
				swapStr(s);
				st.insert(s);
			}
			cnt++;
		}
	}

	cout << cnt;

}