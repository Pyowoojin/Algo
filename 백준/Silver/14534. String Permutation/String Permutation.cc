#include <bits/stdc++.h>
using namespace std;

vector <char> vc;

void dfs(string s, bool visited[]) {
	if (vc.size() == s.length()) {
		for (int i = 0; i < vc.size(); i++) {
			cout << vc[i];
		}
		cout << endl;
		return;
	}

	for (int k = 0; k < s.length(); k++) {
		if (visited[k] == false) {
			visited[k] = true;
			vc.push_back(s[k]);
			dfs(s, visited);
			vc.pop_back();
			visited[k] = false;
			
		}
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	
	int z = 1;
	while (n--) {
		string s; cin >> s;
		bool* visited = new bool[s.length()];

		for (int i = 0; i < s.length(); i++) {
			visited[i] = false;
		}
		cout << "Case # " << z << ": \n";
		dfs(s, visited);
		z++;
	}
}