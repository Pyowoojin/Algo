#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;

	int total = 0;
	int leftKG = 0;

	while (a > 0 || b > 0 || c > 0 || d > 0 || e > 0) {
		//cout << a << " " << b << " " << c << " " << d << " " << e << endl;
		
		if (leftKG != 5) {
			leftKG = 5;
			total++;
		}

		if (e > 0 && leftKG > 4) {
			e--;
			leftKG = 0;
		}

		if (d > 0 && leftKG > 3) {
			d--;
			leftKG -= 4;
		}

		if (c > 0 && leftKG > 2) {
			c--;
			leftKG -= 3;
		}

		if (b > 0 && leftKG > 1) {
			while (1 < leftKG && b > 0) {
				b--;
				leftKG -= 2;
			}
		}

		if (a > 0 && leftKG > 0) {
			while ((0 < leftKG) && a > 0) {
				a--;
				leftKG--;
			}
		}
	}

	cout << total;
}