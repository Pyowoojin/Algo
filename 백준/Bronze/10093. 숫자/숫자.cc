#include <bits/stdc++.h>
using namespace std;

int main() {
	cout.tie(NULL);
	ios_base::sync_with_stdio(0);
	unsigned long long ta, tb; cin >> ta >> tb;
	if (ta == tb)
		cout << "0";
	else {
		unsigned long long a = min(ta, tb);
		unsigned long long b = max(ta, tb);
		cout << b - a - 1 << endl;
		for (unsigned long long i = a + 1; i < b; i++) {
			cout << i << " ";
		}
	}
}