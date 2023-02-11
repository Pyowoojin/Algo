#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int cnt = 0;

class Node {
public :
	Node* child[26] = { nullptr, };
	bool finished = false;

	Node() {
		for (int i = 0; i < 26; i++) {
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

	Trie() {
		root = new Node();
	}

	void Insert(Node *cur, const char *str) {
		// 마지막 문자일 경우
		if (*str == '\0') {
			cur->finished = true;
			return;
		}
		else {
			int c = *str - 'a';
			if (cur->child[c] == nullptr)
				cur->child[c] = new Node();
			this->Insert(cur->child[c], str + 1);
		}
		// cout << "한 번 들어감\n";
	}

	void SortingPrt(Node* cur, string& str) {
		if (cur->finished == true) {
			cout << str << endl;
		}

		for (int i = 0; i < 26; i++) {
			if (cur->child[i] != nullptr) {
				str += i + 'a';
				SortingPrt(cur->child[i], str);
				str.pop_back();
			}
		}
	}

	void CheckSuffix(Node* cur, const char* str) {
		if (*str == '\0') {
			cnt++;
			return;
		}
		for (int i = 0; i < 26; i++) {
			if (cur->child[*str - 'a'] != nullptr) {
				CheckSuffix(cur->child[*str - 'a'], str + 1);
				return;
			}
			else
				return;
		}
	}
};

int main() {
	Trie* tr = new Trie();

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		tr->Insert(tr->root, &s[0]);
	}

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		tr->CheckSuffix(tr->root, &s[0]);
	}

	cout << cnt;


	return 0;
}