#include <bits/stdc++.h>
using namespace std;

void insert(vector <map<string, int>>& tree, int size, string target, int depth) {
	
	map <string, int> mp;
	if (size == 0)
		return;

	// cout << "before emplace back size : " << tree.size() << endl;
	// cout << "depth : " << depth << endl;
	
	// vector의 크기가 depth만큼 없다면, depth만큼 늘려준다
	if (tree.size() < depth + 1) {
		for (int i = 0; i < depth + 1; i++) {
			tree.emplace_back();
		}
	}

	// cout << "after emplace back size : " << tree.size() << endl;

	// cout << "트리의 사이즈 : " << tree.size() << "  ";

	// 해당 Depth에 중복되는 문자가 있다면
	if (tree[depth].find(target) != tree[depth].end()) {
		// cout << "재귀 실행\n";
		insert(tree, size, target, depth + 1);
	}
	else {
		// 해당 깊이에 target을 넣어줌
		// cout << depth << "깊이에 " << target << "insert\n";
		tree[depth].insert({ target,depth });
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*int n; cin >> n;

	vector <map<string, int>> tree;
	map <string, int> tmp;

	while (n--) {
		int m; cin >> m;
		
		for (int i = m; i > 0; i--) {
			string target; cin >> target;
			insert(tree, m, target, 0);
		}
	}

	for (int i = 0; i < tree.size(); i++) {
		for (auto k = tree[i].begin(); k != tree[i].end(); k++)
			cout << k->first << " ";
		cout << endl;
	}*/

	while (1) {
		int c; cin >> c;
		if (c == 0)
			break;
		vector <int> vc;
		for (int i = 0; i < c; i++) {
			int k; cin >> k;
			vc.push_back(k);
		}

		auto it = unique(vc.begin(), vc.end());
		
		vc.erase(it, vc.end());

		for (auto i : vc)
			cout << i << " ";

		cout << "$\n";
	}


}