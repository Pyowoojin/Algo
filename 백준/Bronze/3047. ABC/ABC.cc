#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	int rA, rB, rC;

	string ord; cin >> ord;

	rA = min({ a,b,c });
	rC = max({ a,b,c });

	// a를 위한 if
	if (rA != a && rC != a)
		rB = a;
	else if (rA != b && rC != b)
		rB = b;
	else
		rB = c;

	for (int i = 0; i < 3; i++) {
		if (ord[i] == 'A')
			cout << rA << " ";
		else if (ord[i] == 'B')
			cout << rB << " ";
		else
			cout << rC << " ";
	}

}