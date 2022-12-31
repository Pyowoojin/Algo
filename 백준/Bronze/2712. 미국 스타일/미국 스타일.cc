#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int tc; cin >> tc;

	vector <pair <float, string>> vc;

	float onekgSizeTolb = 2.2046;
	float onelbSizeTokg = 0.4536;
	float onelitterSizeTogallon = 0.2642;
	float onegallonSizeTolitter = 3.7854;

	for (int i = 0; i < tc; i++) {
		float a; string c; cin >> a >> c;

		if (c == "kg") {
			cout << fixed;
			cout.precision(4);
			cout << a * onekgSizeTolb << " lb" << endl;
		}
		else if (c == "lb") {
			cout << fixed;
			cout.precision(4);
			cout << a * onelbSizeTokg << " kg" << endl;
		}
		else if(c == "l") {
			cout << fixed;
			cout.precision(4);
			cout << a * onelitterSizeTogallon << " g" << endl;
		}
		else {
			cout << fixed;
			cout.precision(4);
			cout << a * onegallonSizeTolitter << " l" << endl;
		}
	}
}