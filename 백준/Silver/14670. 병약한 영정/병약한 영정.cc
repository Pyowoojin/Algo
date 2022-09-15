#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

int ans = -1;

template <typename T>
void prt(const vector <T>& v1) {
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) {
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
}

int arr[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(arr, arr + 101, -99);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr[a] = b;
	}

	int symptom; cin >> symptom;

	vector <int> tmp;
	vector <vector <int>> vc(symptom, tmp);
	vector <vector <int>> ans(vc);

	for (int i = 0; i < symptom; i++) {
		int c; cin >> c;
		for (int j = 0; j < c; j++) {
			int k = 0; cin >> k;
			vc[i].push_back(k);
		}
	}

	for (int i = 0; i < symptom; i++) {
		for (int j = 0; j < vc[i].size(); j++) {
			int temp = arr[vc[i][j]];
			vc[i][j] = temp;
		}
	}

	vector <int> ansTemp; 

	bool flag = false;

	for (int i = 0; i < symptom; i++) {
		flag = false;
		for (int j = 0; j < vc[i].size(); j++) {
			ansTemp.push_back(vc[i][j]);
			if (vc[i][j] == -99) {
				flag = true;
			}
		}
		if (flag) {
			cout << "YOU DIED";
		}
		else {
			for (int i = 0; i < ansTemp.size(); i++)
				cout << ansTemp[i] << " ";
		}
		cout << '\n';
		ansTemp.clear();
	}

}