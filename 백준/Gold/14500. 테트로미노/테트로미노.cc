#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector <vector <int>> vc(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vc[i][j];
		}
	}
	
	int maxCount = 0;

	// ㅁ 모양 블록

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// ㅡ 모양 블록
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m - 4; j++) {
			int curCount = 0;
			for (int k = j; k < j + 4; k++) {
				curCount += vc[i][k];
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// ㅣ 모양 블록

	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j < m; j++) {
			int curCount = 0;
			for (int k = i; k < i + 4; k++) {
				curCount += vc[k][j];
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 세로로 긴 └ 모양 블록

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i && l == j + 1) {
						curCount -= vc[k][l];
					}
					else if (k == i + 1 && l == j + 1) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 세로로 긴 ┘ 모양 블록

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 1 && l == j) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 세로로 긴 ┐ 모양 블록

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i + 1 && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 2 && l == j) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 세로로 긴 ┌ 모양 블록

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i + 1 && l == j + 1) {
						curCount -= vc[k][l];
					}
					else if (k == i + 2 && l == j + 1) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 가로로 긴 ㄴ자 모양 블록

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i && l == j + 1) {
						curCount -= vc[k][l];
					}
					else if (k == i && l == j + 2) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 가로로 긴 ㄱ자 모양 블록

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i + 1&& l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 1 && l == j + 1) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 가로로 긴 「 자 모양 블록

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i + 1 && l == j + 1) {
						curCount -= vc[k][l];
					}
					else if (k == i + 1 && l == j + 2) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// 가로로 긴 」 자 모양 블록

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i && l == j + 1) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// Z 모양 세로 블록

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i && l == j + 1) {
						curCount -= vc[k][l];
					}
					else if (k == i + 2 && l == j) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// Z 모양 세로 블록 (반전)

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 2 && l == j + 1) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// Z모양 가로 블럭

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i + 1 && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i && l == j + 2) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// Z 모양 가로 블럭 (반전)

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 1 && l == j + 2) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// ㅗ 모양 블럭 

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i && l == j + 2) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// ㅜ 모양 블럭

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			int curCount = 0;
			for (int k = i; k < i + 2; k++) {
				for (int l = j; l < j + 3; l++) {
					curCount += vc[k][l];
					if (k == i + 1 && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 1 && l == j + 2) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// ㅓ 모양 블럭

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i && l == j) {
						curCount -= vc[k][l];
					}
					else if (k == i + 2 && l == j) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}

	// ㅏ 모양 블럭

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			int curCount = 0;
			for (int k = i; k < i + 3; k++) {
				for (int l = j; l < j + 2; l++) {
					curCount += vc[k][l];
					if (k == i && l == j + 1) {
						curCount -= vc[k][l];
					}
					else if (k == i + 2 && l == j + 1) {
						curCount -= vc[k][l];
					}
				}
			}
			if (curCount > maxCount)
				maxCount = curCount;
		}
	}


	cout << maxCount;
}