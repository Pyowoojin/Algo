#include <bits/stdc++.h>
using namespace std;

// s1은 total, s2는 앞 뒤만 바꾼 짧은 문자열
string MyPlus(string& s1, string& s2) {
	string result;

	int s1_len = s1.length();
	int s2_len = s2.length();

	// 짧은 문자열 0으로 패딩
	for (int i = 0; i < s1_len - s2_len; i++)
		s2.insert(0, "0");

	// cout << s1 << " / " << s2 << endl;

	bool roundUp = false;
	int i = s1.length() - 1;
	for (int j = s2.length() -1; i > -1; i--, j--) {
		int k = 0;

		k = (s1[i] - '0') + (s2[i] - '0');

		// 올림이 있을 경우에 +1 해주고 result에 값 더해줌
		if (roundUp) {
			k++;
			result.insert(0, to_string((k % 10)));
			roundUp = false;
			if (k > 9) {
				roundUp = true;
				if (i == 0)
					result.insert(0, "1");
			}
		}
		// 올림이 없을 경우 다음 자리를 위한 올림 체크를 해주고 result에 값 더해줌
		else {
			if (k > 9) {
				roundUp = true;
				result.insert(0, to_string((k % 10)));
				if (i == 0)
					result.insert(0, "1");
			}
			else {
				result.insert(0, to_string((k % 10)));
			}
		}

		// cout << result << "\n";
		
	}


	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*string s; cin >> s;
	deque <char> dq;

	for (int i = 0; i < s.length(); i++) {
		dq.push_back(s[i]);
	}

	string total = s;
	
	while (1) {
		bool check = true;

		char c = dq.back();
		dq.pop_back();
		dq.push_front(c);

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] != s[i]) {
				check = false;
				break;
			}
		}

		if (check)
			break;

		string tmp;
		for (int j = 0; j < dq.size(); j++)
			tmp += dq[j];

		// cout << total << " + " << tmp << " = ";
		total = MyPlus(total, tmp);


		// cout << total << endl;

	}

	cout << total;*/

	string s1, s2; cin >> s1 >> s2;
	string maxS = s1, minS = s2;

	if (s1.length() > s2.length()) {
		maxS = s1;
		minS = s2;
	}
	else if (s1.length() < s2.length()) {
		maxS = s2;
		minS = s1;
	}


	cout << MyPlus(maxS, minS);

}