#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(const vector <T>& vc) {
	for (int i = 0; i < vc.size(); i++) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << " ";
		}
		cout << '\n';
	}
	 cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;

	while (tc){
		int n; cin >> n;
		vector <int> vc;
		int min = 1000001;
		int max = -1000001;
		for (int i = 0; i < n; i++) {
			int c; cin >> c;
			vc.push_back(c);
			if (max < c)
				max = c;
			if (min > c)
				min = c;
		}

		cout << min << " " << max << '\n';
		tc--;
	}
}


