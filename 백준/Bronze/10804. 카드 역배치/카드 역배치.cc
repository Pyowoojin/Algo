#include <bits/stdc++.h>
using namespace std;

int main() {
	vector <int> vc(20);
	for (int i = 1; i <= 20; i++) {
		vc[i - 1] = i;
	}

	for (int i = 0; i < 10; i++) {
		int start, end; cin >> start >> end;
		reverse(vc.begin()+start-1, vc.begin() + end);
	}

	for (auto i : vc)
		cout << i << " ";
}