#include <bits/stdc++.h>

using namespace std;

bool customostr(string a, string b) {
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i])
				return a[i] < b[i];
		}
	}

	return a.length() < b.length();
}

int main() {
	vector <string> str;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string temp; cin >> temp;
		str.push_back(temp);
	}
	
	sort(str.begin(), str.end(), customostr);
	str.erase(unique(str.begin(), str.end()), str.end());

	for (auto& n : str) {
		cout << n << endl;
	}
}
