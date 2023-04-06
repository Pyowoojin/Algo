#include <bits/stdc++.h>
using namespace std;

int main() {
	long long maxN; cin >> maxN;

	long long i = 1;
	long long total = 0;

	while (total <= maxN) {
		total += i;
		i++;
	}

	cout << i - 2;
}