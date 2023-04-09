#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int l = 0, s = 0;
	
	string str; cin >> str;
	int totalCnt = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			totalCnt++;
		}
		else if (str[i] == 'L') {
			l++;
		}
		else if (str[i] == 'S') {
			s++;
		}
		else if (str[i] == 'R') {
			if (l > 0) {
				l--;
				totalCnt++;
			}
			else
				break;
		}
		else if (str[i] == 'K') {
			if (s > 0) {
				s--;
				totalCnt++;
			}
				
			else
				break;
		}
	}

	cout << totalCnt;
}