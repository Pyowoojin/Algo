#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack <char> st;
	string s, transS = "";
	getline(cin, s);

	for (int i = 0; i < s.length();) {
		// <>안의 문자열 처리
		if (s[i] == ' ') {
			transS += " ";
			i++;
		}
		else if (s[i] == '<') {
			int k = 1;
			while (k) {
				if (s[i] == '>') {
					transS += s[i];
					i++;
					k = 0;
				}
				else {
					transS += s[i];
					i++;
				}
			}
		}
		else if (s[i] != ' ' && s[i] != '<' && i!=s.length() && s[i] != '>') {
			while (s[i] != ' ' && s[i] != '<' && i != s.length() && s[i] != '>') {
				st.push(s[i]);
				i++;
			}
			while (!st.empty()) {
				transS += st.top();
				st.pop();
			}
		}

	}
	cout << transS;
}