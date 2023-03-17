#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long m, n; cin >> m >> n;
	vector <long long> vc;
	long long total = 0;

	for (long long i = 1; i <= n; i++) {
		vc.push_back(i * i);
	}

	long long* start = nullptr;
	bool flag = false;
	long long first = 0;

	for (auto i : vc)
	{
		if (i > n)
			break;
		if (i >= m && !flag) {
			first = i;
			start = &i;
			flag = true;
		}
		if (start != nullptr) {
			total += i;
		}
	}

	if (start == nullptr)
		cout << "-1";
	else {
		cout << total << endl << first;
	}

}