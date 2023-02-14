#include <bits/stdc++.h>
using namespace std;

int main() {
	/*cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);*/

	int tc; cin >> tc; cin.ignore();

	while (tc--) {
		list <string> ls;

		// 동물 소리 녹음
		string s;
		string tmp;

		getline(cin, s);
		stringstream ss(s);

		while (ss >> tmp)
			ls.push_back(tmp);

		while (1) {
			string last;
			getline(cin, s);

			if (s == "what does the fox say?")
				break;

			istringstream iss(s);
			iss >> last >> last >> last;

			ls.remove(last);
		}

		for (auto i = ls.begin(); i != ls.end(); i++)
			cout << *i << " ";
		cout << '\n';
	}

}