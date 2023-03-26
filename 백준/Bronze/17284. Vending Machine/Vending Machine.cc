#include <bits/stdc++.h>
using namespace std;

int main() {
	int total = 5000;
	char c;
	while (cin >> c) {
		if (c == '1') {
			total -= 500;
		}
		if (c == '2')
			total -= 800;
		if (c == '3')
			total -= 1000;
	}

	cout << total;
}