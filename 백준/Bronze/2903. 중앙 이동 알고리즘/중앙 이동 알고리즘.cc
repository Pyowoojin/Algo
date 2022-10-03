#include <bits/stdc++.h>
using namespace std;

void ca(int x) {
	int two = 2;
	int a = pow(two, x) + 1;
	cout << a * a;
}

int main() {
	int n;
	cin >> n;
	ca(n);

}