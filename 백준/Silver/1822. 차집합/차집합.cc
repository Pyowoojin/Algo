#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int a, b; cin >> a >> b;
	set <int> st1, st2, st3;
	vector <int> vc(a);

	for (int i = 0; i < a; i++) {
		cin >> vc[i];
	}

	for (int i = 0; i < b; i++) {
		int c; cin >> c;
		st2.insert(c);
	}

	for (int i = 0; i< a; i++){
		// 이렇게 되면 A에는 속하지만 B에는 속하지 않는 원소임
		if (st2.find(vc[i]) == st2.end()) {
			st3.insert(vc[i]);
		}
	}
	cout << st3.size() << endl;

	for (auto i : st3) {
		cout << i << " ";
	}
}