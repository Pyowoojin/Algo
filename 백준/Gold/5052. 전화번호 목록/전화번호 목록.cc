#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Node {
public :
	Node* child[10] = { nullptr, };
	bool finished = false;

	Node() {
		for (int i = 0; i < 10; i++) {
			child[i] = nullptr;
		}
	}
	~Node() {
		delete child;
	}
};

class Trie {
public :
	Node* root;
	bool ans;
	Trie() {
		root = new Node();
		ans = true;
	}

	void Insert(Node *cur, const char *str) {
		// 마지막 문자일 경우
		if (*str == '\0') {
			cur->finished = true;
			return;
		}
		else {
			int c = *str - '0';
			if (cur->child[c] == nullptr)
				cur->child[c] = new Node();
			if (cur->finished == true) {
				ans = false;
			}
			this->Insert(cur->child[c], str + 1);
		}
	}

	void SortingPrt(Node* cur, string& str) {
		if (cur->finished == true) {
			// cout << str << endl;
			for (int i = 0; i < 10; i++) {
				if (cur->child[i] != nullptr) {
					ans = false;
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			if (cur->child[i] != nullptr) {
				str += i + '0';
				SortingPrt(cur->child[i], str);
				str.pop_back();
			}
		}
	}
};

int main() {
	int tc; cin >> tc;

	while (tc--) {
		Trie* tr = new Trie();
		string st = "";

		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			tr->Insert(tr->root, &s[0]);
		}

		tr->SortingPrt(tr->root, st);
		
		if (!tr->ans)
			cout << "NO\n";
		else
			cout << "YES\n";

	}

	return 0;
}