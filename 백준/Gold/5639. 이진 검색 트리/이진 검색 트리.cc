#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node* left = nullptr;
	Node* right = nullptr;
};

class bst {
public :
	void insert(int x, Node* n);
	int cnt = 0;
	int total = 0;
	Node* root = nullptr;
	void postOrder(Node* n);
};

void bst::postOrder(Node* n) {
	if (n->left != nullptr)
		postOrder(n->left);
	if (n->right != nullptr)
		postOrder(n->right);
	cout << n->key << '\n';
}

void bst::insert(int x, Node* n) {
	cnt++;

	if (root == nullptr)
	{
		Node* newNode = new Node();
		newNode->key = x;
		root = newNode;
		return;
	}

	if (x < n->key) {
		if (n->left == nullptr) {
			Node* newNode = new Node();
			newNode->key = x;
			n->left = newNode;
		}
		else {
			insert(x, n->left);
		}
	}
	else {
		if (n->right == nullptr) {
			Node* newNode = new Node();
			newNode->key = x;
			n->right = newNode;
		}
		else {
			insert(x, n->right);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bst tree;
	int c;
	while (1) {
		cin >> c;
		if (cin.eof() == true)
			break;

		tree.insert(c, tree.root);
	}
	tree.postOrder(tree.root);
}