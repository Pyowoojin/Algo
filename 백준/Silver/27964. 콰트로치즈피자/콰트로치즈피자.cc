#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	set<string> st;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s.length() >= 6) {
			// 끝 6자리를 골라냄
			string cheese = s.substr(s.length() - 6, 6);
			// 그게 cheese라면 셋에 넣어줌
			if(cheese == "Cheese")
				st.insert(s);
		}
	}

	// 치즈의 종류가 4개 이상이라면 yummy 아니면 sad!
	if (st.size() > 3) {
		cout << "yummy";
	}
	else
		cout << "sad";
}