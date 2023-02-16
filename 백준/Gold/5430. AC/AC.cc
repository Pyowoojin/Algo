#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;

	while (tc--) {

		bool dir = true;
		bool err = false;

		deque <int> dq;

		// 명령어 입력
		string oper; cin >> oper;

		// 배열 사이즈 입력
		int arrSize; cin >> arrSize;
		int breakCount = arrSize + 1;
		
		// 배열 내용 입력 [1,2,3,4]
		string arrString; cin >> arrString;
		int strPtr = 0;

		string tmp;
		while (breakCount) {
			if (arrString[strPtr] >= '0' && arrString[strPtr] <= '9') {
				tmp += arrString[strPtr];
			}
			else if (arrString[strPtr] == ',' || arrString[strPtr] == ']') {
				if(tmp.length())
					dq.push_back(stoi(tmp));
				tmp = "";
				breakCount--;
			}
			else
				breakCount--;

			strPtr++;
		}

		for (int i = 0; i < oper.length(); i++) {
			if (oper[i] == 'R') {
				dir = !dir;
			}
			else if (oper[i] == 'D') {
				if (dq.empty()) {
					err = true;
					break;
				}

				if (dir) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}

		if (err) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (!dir) {
				for(int i = dq.size()-1; i > -1 ; i--){
					cout << dq[i];
					if (i != 0)
						cout << ",";
				}
			}
			else {
				for (auto i =0; i < dq.size(); i++) {
					cout << dq[i];
					if (i +1 != dq.size())
						cout << ",";
				}
			}
			cout << "]\n";
		}

	}
}