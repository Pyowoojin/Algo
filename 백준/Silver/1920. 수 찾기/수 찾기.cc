#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map <int, int> my;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		my.insert({ temp, temp % 100 });
		// cin.ignore();
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		if (my.find(temp) != my.end()) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
		//cin.ignore();
	}
}