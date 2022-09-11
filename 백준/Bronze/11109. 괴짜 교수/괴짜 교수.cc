#include <bits/stdc++.h>
using namespace std;

int main() {
	int numOfCase;
	cin >> numOfCase;
	vector <string> st;

	while (numOfCase) {
		int d, n, s, p, ifParal, ifNotParal;
		cin >> d >> n >> s >> p;
		ifParal = d + n * p;
		ifNotParal = n * s;

		if (ifParal < ifNotParal) {
			st.push_back("parallelize");
		}
		else if (ifParal == ifNotParal) {
			st.push_back("does not matter");
		}
		else {
			st.push_back("do not parallelize");

		}

		numOfCase--;
	}

	for (int i = 0; i < st.size(); i++) {
		cout << st[i] << endl;
	}

}