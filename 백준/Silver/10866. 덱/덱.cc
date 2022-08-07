#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class myDeque {
private:
	int cnt = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	void push_f(int n);
	void push_b(int n);
	int pop_f();
	int pop_b();
	int size();
	bool empty();
	int front();
	int back();
	void trav();
};

void myDeque::push_f(int n) {
	Node* nNode = new Node;
	nNode->data = n;
	nNode->next = nullptr;
	nNode->prev = nullptr;
	if (empty()) {
		head = nNode;
		tail = nNode;
	}
	else {
		nNode->next = head;
		head->prev = nNode;
		head = nNode;
	}
	cnt++;
}
void myDeque::push_b(int n) {
	Node* nNode = new Node;
	nNode->data = n;
	nNode->next = nullptr;
	nNode->prev = nullptr;
	if (empty()) {
		tail = nNode;
		head = nNode;
	}
	else {
		nNode->prev = tail;
		tail->next = nNode;
		tail = nNode;
	}
	cnt++;

}
int myDeque::pop_f() {
	int t;
	if (!empty()) {
		cnt--;
		Node* nN = head;
		t = nN->data;
		head = nN->next;
		if (head != nullptr)
			head->prev = nullptr;
		delete(nN);
		return t;
	}
	else {
		return -1;
	}
}
int myDeque::pop_b() {
	int t;
	if (!empty()) {
		cnt--;
		Node* nN = tail;
		t = nN->data;
		tail = nN->prev;
		if(tail != nullptr)
			tail->next = nullptr;
		delete(nN);
		return t;
	}
	else {
		return -1;
	}
}
bool myDeque::empty() {
	if (cnt == 0)
		return 1;
	return 0;
}
int myDeque::size() {
	return cnt;
}
int myDeque::front() {
	if (!empty())
		return head->data;
	return -1;
}
int myDeque::back() {
	if (!empty())
		return tail->data;
	return -1;
}

void myDeque::trav() {
	if (!empty()) {
		Node* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	myDeque md;
	vector <int> ans;
	int n; cin >> n;
	cin.ignore();

	while (n) {
		string s;
		getline(cin, s);
		if (s.length() > 10) {
			//stoi(s.substr(5, 1));
			string data = s.substr(5, 1);
			if (data == "b") {
				md.push_b(stoi(s.substr(10, 8)));
			}
			else if (data == "f") {
				md.push_f(stoi(s.substr(11, 8)));
			}
		}
		else if (s == "pop_front") {
			ans.push_back(md.pop_f());
		}
		else if (s == "pop_back") {
			ans.push_back(md.pop_b());
		}
		else if (s == "size") {
			ans.push_back(md.size());
		}
		else if (s == "empty") {
			ans.push_back(md.empty());
		}
		else if (s == "front") {
			ans.push_back(md.front());
		}
		else if (s == "back") {
			ans.push_back(md.back());
		}
		else if (s == "trav") {
			md.trav();
		}
		n--;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

}