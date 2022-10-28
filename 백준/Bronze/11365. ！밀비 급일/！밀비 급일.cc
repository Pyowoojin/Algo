#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string str;
		getline(cin, str);
		if (str == "END")
			break;
		
		for (int i = str.length() - 1; i > -1; i--) {
			cout << str[i];
		}
		cout << '\n';
	}

}