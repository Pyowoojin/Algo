#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	int c = 0;
	for(int i = 32; i>0; i--){
		if ((n & (1 << i - 1)) != (((~n + 1) & ( 1 << i -1)))) {
			c++;
		}
	}
	
	cout << c;

}