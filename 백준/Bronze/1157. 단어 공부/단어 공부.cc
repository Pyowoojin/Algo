#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	int arr[26] = { 0, };
	int i = 0;
	while (i < s.length()) {
		arr[(s[i] - '0') - 17] += 1;
		i++;
	}
	int max = 0;
	int maxIndex = 0;
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			maxIndex = i;
			max = arr[i];
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == arr[i]) 
			count++;
	}

	if (count > 1) {
		cout << "?";
	}
	else {
		cout << char(maxIndex + 17 + '0');
	}

}