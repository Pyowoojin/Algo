#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class myStack {
private:
	int nCnt = 0;
	Node* head = NULL;
	Node* tail = NULL;


public:
	myStack() {};
	~myStack() {};

public:
	void push(int num);
	int pop();
	int size();
	bool empty();
	int top();
	void trav();

};

bool myStack::empty() {
	if (nCnt == 0)
		return 1;
	else
		return 0;
}

int myStack::top() {
	if (nCnt == 0)
		return -1;
	return head->data;
}

void myStack::push(int n) {
	Node* newNode = new Node();
	newNode->data = n;
	newNode->next = nullptr;
	if (nCnt == 0) {
		head = newNode;
		nCnt++;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		nCnt++;
	}
}

int myStack::pop() {
	int temp;
	if (nCnt == 0)
		return -1;
	else{
		temp = head->data;
		head = head->next;
		nCnt--;
		return temp;
	}
}

int myStack::size() {
	return nCnt;
}

void myStack::trav() {
	Node* ptr = head;
	while (ptr!=nullptr) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	myStack q;
	vector <int> ans;
	int n; cin >> n;
	cin.ignore();
	while (n) {
		string s;
		getline(cin, s);
		if (s.length() > 5) {
			int data = stoi(s.substr(5, s.length() - 5));
			q.push(data);
		}
		else if (s == "pop")
			ans.push_back(q.pop());
		else if (s == "size")
			ans.push_back(q.size());
		else if (s == "empty")
			ans.push_back(q.empty());
		else if (s == "top")
			ans.push_back(q.top());
		else if (s == "empty")
			ans.push_back(q.empty());
		n--;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

}