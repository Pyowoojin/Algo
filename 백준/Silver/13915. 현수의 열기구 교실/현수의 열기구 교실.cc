#include <bits/stdc++.h>
#include <set>
using namespace std;

int arr[10];

void init() {
	for (int i = 0; i <= 9; i++)
		arr[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	// 배열로 숫자들을 저장하고, 1~9까지 정렬함
	// 그 숫자를 hash map에 저장함. hash map의 수가 분류 슈ㅜ
	set <string> st;
	while (cin >> n) {
		cin.ignore();
		for (int i = 0; i < n; i++) {
			init();
			string s; cin >> s;

			for (int i = 0; i < s.length(); i++) {
				arr[s[i] - '0'] = 1;
			}
			string tmp = "";
			for (int i = 1; i <= 9; i++) {
				if (arr[i] == 1) {
					tmp += to_string(i);
				}
			}
			st.insert(tmp);
		}
		cout << st.size() << '\n';
		st.clear();
	}


}