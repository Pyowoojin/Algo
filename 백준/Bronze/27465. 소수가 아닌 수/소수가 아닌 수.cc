#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	
	if (n < 5)
		cout << "4";
	else if (n % 2 == 1)
		cout << n + 1;
	else
		cout << n;

}