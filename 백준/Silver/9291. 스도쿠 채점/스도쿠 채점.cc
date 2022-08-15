#include <bits/stdc++.h>
using namespace std;

int arr[9] = { 1,2,3,4,5,6,7,8,9 };

void print(const vector <vector<int>>& sudoku) {
	cout << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

void init() {
	for (int i = 1; i < 10; i++)
		arr[i - 1] = i;
}

int chk(const vector <vector<int>>& sudoku) {
	init();
	// 행 확인 
	for (int i = 0; i < 9; i++) {
		init();
		for (int j = 0; j < 9; j++) {
			if (arr[sudoku[i][j] - 1] == 0) {
				return -1;
			}
			else {
				arr[sudoku[i][j] - 1] = 0;
			}
		}
	}

	// 열 확인

	for (int i = 0; i < 9; i++) {
		init();
		for (int j = 0; j < 9; j++) {
			if (arr[sudoku[j][i] - 1] == 0) {
				return -1;
			}
			else {
				arr[sudoku[j][i] - 1] = 0;
			}
		}
	}

	// 3 X 3 칸 확인
	for (int o = 0; o < 3; o++) {
		for (int k = 0; k < 3; k++) {
			init();
			for (int i = k * 3; i < k * 3 + 3; i++) {
				for (int j = o*3; j < o*3+3; j++) {
					if (arr[sudoku[i][j] - 1] == 0) {
						return -1;
					}
					else {
						arr[sudoku[i][j] - 1] = 0;
					}
				}

			}
		}
	}

	return 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <int> v(9, 0);
	vector <vector<int>> sudoku(9, v);
	vector <int> ans;
	int t; cin >> t;
	for (int z = 0; z < t; z++) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int n; cin >> n;
				sudoku[i][j] = n;
			}
		}
		ans.push_back(chk(sudoku));
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << "Case " << i + 1 << ": ";
		if (ans[i] == -1)
			cout << "INCORRECT\n";
		else
			cout << "CORRECT\n";
	}

}