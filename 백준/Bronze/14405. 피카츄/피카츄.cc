#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	bool ans = true;
	
	vector <string> vc(3);
	vc[0] = "pi";
	vc[1] = "ka";
	vc[2] = "chu";

	int i = 0;
	int q = 0;
	while (i < s.length()) {
		bool continueFlag = false;
		for (int k = 0; k < 3; k++) {

			string compStr = s.substr(i, vc[k].size());
			int plusSize = vc[k].size();
			bool isCorrect = true;
			for (int l = 0; l < vc[k].size(); l++) {
				if (compStr[l] != vc[k][l]) {
					isCorrect = false;
					break;
				}
			}
			if (isCorrect) {
				i += plusSize;
				q += plusSize;
				continueFlag = true;
				break;
			}
		}

		if (continueFlag) {
			continue;
		}
		ans = false;
		break;
		i++;
	}

	if (ans)
		cout << "YES";
	else
		cout << "NO";

}