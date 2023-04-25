#include <bits/stdc++.h>
using namespace std;

int arr[26];
int arr2[26];

int main() {
	string s1, s2; cin >> s1 >> s2;
	int total = 0;

	for (int i = 0; i < s1.length(); i++) {
		arr[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.length(); i++) {
		arr2[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] != arr2[i]) {
			total += abs(arr[i] - arr2[i]);
		}
	}

	cout << total;
}