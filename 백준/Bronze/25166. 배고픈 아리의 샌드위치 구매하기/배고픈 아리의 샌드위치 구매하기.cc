#include <bits/stdc++.h>
using namespace std;

int main() {

	int s, m; cin >> s >> m;

	string ari = "1111111111";
	int initMoney = 512;
	
	string coogie = "0000000000";
	int coogiesMoney = 1;
	// 쿠기의 동전 초기화

	int init = 512;

	int cnt = 0;
	while (m) {
		if (m >= init) {
			m -= init;
			coogie[cnt] = '1';
		}
		init = init >> 1;
		cnt++;
	}

	cnt = 0;
	while (s && cnt < 10) {
		if (s >= initMoney) {
			s -= initMoney;
			ari[cnt] = '0';
		}

		initMoney = initMoney >> 1;
		cnt++;
	}

	if (s == 0) {
		cout << "No thanks";
	}

	else {
		cnt = 9;
		int totalMoney = 0;
		init = 1;
		while (s && cnt > -1) {
			if (coogie[cnt] == '1') {
				if (s >= init) {
					s -= init;
					coogie[cnt] = '0';
				}
			}
			init = init << 1;
			cnt--;
		}

		if (s != 0) {
			cout << "Impossible";
		}
		else {
			cout << "Thanks";
		}
	}

}