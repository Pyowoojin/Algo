#include <iostream>
using namespace std;

int main(){
	int n, k = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i < 100 || i % 10 + i / 100 == i / 10 % 10 * 2)
			k++;
	}
	cout << k;
}