#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b; cin >> a >> b;
	int c, d; cin >> c >> d;

	int child = a * d + c * b;
	int parent = b * d;

	// cout << child << " / " << parent << endl;

	int gi = gcd(child, parent);


	cout << child / gi << " " << parent / gi;

}