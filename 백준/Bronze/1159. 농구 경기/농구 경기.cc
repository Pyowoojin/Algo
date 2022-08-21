#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[26] = { 0, };
	
	int z; cin >> z;

	for (int i = 0; i < z; i++) {
		string s; cin >> s;
		arr[s[0] - '0' - 49] += 1;
		cin.ignore();
	}

	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			flag = 1;
			cout << char(i + 97);
		}
	}

	if (!flag)
		cout << "PREDAJA";
}