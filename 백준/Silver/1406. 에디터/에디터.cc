#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string s; cin >> s;
	int n; cin >> n;

	list <char> dq;

	for (int i = 0; i < s.length(); i++) {
		dq.push_back(s[i]);
	}
	
	auto ptr = dq.end();

	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		char newChar;
		if (input == "P") {
			cin >> newChar;
			dq.insert(ptr, newChar);
		}
		else if(input == "L") {
			if (ptr != dq.begin()) {
				ptr--;
			}
		}
		else if(input == "D") {
			if (ptr != dq.end()) {
				ptr++;
			}
		}
		else {
			auto temp = ptr;
			if (temp != dq.begin()) {
				temp--;
				dq.erase(temp);
			}
		}
	}

	for (auto i : dq)
		cout << i;

}