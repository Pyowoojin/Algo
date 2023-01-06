#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c; cin >> a >> b >> c;

	if (a + b + c >= 100)
		cout << "OK";
	else if (a < b && a < c)
		cout << "Soongsil";
	else if (b < a && b < c)
		cout << "Korea";
	else if (c < b && a > c)
		cout << "Hanyang";
}