#include <bits/stdc++.h>
#define ll long long
using namespace std;

char arr[100][100];

template <typename T>
void prt(vector <T>& vc) {
	for (int i = vc.size() -1; i > -1 ; i--) {
		for (int j = 0; j < vc[0].size(); j++) {
			cout << vc[i][j] << "";
		}
		cout << endl;
	}
}

void prtt(char arr[100][100]) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << arr[i][j] << "";
		}
		cout << endl;
	}
	cout << endl;
}

char Transformation(char c) {
	map <char, char> mp;
	mp['-'] = '|';
	mp['|'] = '-';
	mp['/'] = '\\';
	mp['\\'] = '/';
	mp['^'] = '<';
	mp['<'] = 'v';
	mp['v'] = '>';
	mp['>'] = '^';
	mp['.'] = '.';
	mp['O'] = 'O';

	return mp[c];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector <char> vc2(n, '0');
	vector <vector <char>> vc(m, vc2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			arr[i][j] = c;
		}
	}

	for (int j = n - 1; j > -1; j--) {
		for (int i = m - 1; i > -1; i--) {
			vc[i][j] = Transformation(arr[j][i]);
		}
	}
	
	prt(vc);
}