#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << "";
		}
		cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	
	int le = s.length();

	stack <char> stk;

	string flag = "true";

	if (le % 2 == 1) {
		int i = 0;
		for (; i < le / 2; i++) {
			stk.push(s[i]);
		}

		i++;

		for (; i < le; i++) {
			if (stk.top() != s[i]) {
				flag = "false";
			}
			stk.pop();
		}
	}
	else{
		int i = 0;
		for (; i < le / 2; i++) {
			stk.push(s[i]);
		}

		for (; i < le; i++) {
			if (stk.top() != s[i]) {
				flag = "false";
			}
			stk.pop();
		}
	}

	cout << flag;

}