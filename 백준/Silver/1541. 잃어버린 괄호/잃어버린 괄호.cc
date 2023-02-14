#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;

	bool minusCheck = false;
	bool lastCheck = false;

	string num = "";
	string nowMinus = "";
	int plusData = 0;
	int minusData = 0;
	int total = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num += s[i];
		}
		else if (s[i] == '+' && minusCheck) {
			minusData += stoi(num);
			num = "";
			lastCheck = false;
		}
		else if (s[i] == '+' && !minusCheck) {
			plusData += stoi(num);
			num = "";
			lastCheck = false;
		}

		if (s[i] == '-') {
			lastCheck = true;
			if (!minusCheck) {
				minusCheck = true;
				plusData += stoi(num);
				num = "";
				total += plusData;
				plusData = 0;
				continue;
			}
			else {
//				minusCheck = false;
				minusData += stoi(num);
				num = "";
				total -= minusData;
				minusData = 0;
				continue;
			}
		}

		// 맨 마지막 숫자일 경우 다 더해주고 끝냄
		if (i == s.length() - 1) {
			total += plusData;
			total -= minusData;
			if (lastCheck)
				minusCheck = true;
			if (minusCheck)
				total += -(stoi(num));
			else
				total += stoi(num);
		}
	}

	cout << total;
}