#include <bits/stdc++.h>
using namespace std;

int main(){
	stack <int> vc;
	int nowTurn = 1;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;

		while (!vc.empty() && vc.top() == nowTurn) {
			nowTurn++;
			vc.pop();
		}

		if (nowTurn == c) {
			nowTurn++;
			continue;
		}
		else
			vc.push(c);
	}

	// cout << nowTurn << endl;

	while (!vc.empty() && vc.top() == nowTurn) {
		nowTurn++;
		vc.pop();
	}

	// cout << nowTurn << endl;

	if (nowTurn == n+1) {
		cout << "Nice";
	}
	else
		cout << "Sad";
}