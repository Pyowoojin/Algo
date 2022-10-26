#include <bits/stdc++.h>
using namespace std;

template <typename T>
void prt(vector <vector<T>>& v1) {
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[0].size(); j++) {
			cout << v1[i][j];
		}
		cout << endl;
	}
}

char white[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
};

char black[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

int chk(const vector<vector<char>>& v1, int startX, int startY, char arr[][8]) {
	int cnt = 0;
	for (int l = 0, i = startX; l < 8; l++, i++) {
		for (int k = 0, j = startY; k < 8; k++, j++) {
			if (arr[l][k] != v1[i][j])
				cnt++;
		}
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	cin.ignore();

	vector<char> v2(m, '0');
	vector<vector<char>> v1(n, v2);

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v1[i][j] = s[j];
		}
	}

	int minN = 0x7fffffff;

	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			minN = min(chk(v1, i, j, white), minN);
			minN = min(chk(v1, i, j, black), minN);
		}
	}

	cout << minN;

}