#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class myQue {
private:
	int count = 0;
	Node* head = NULL;
	Node* tail = NULL;


public:
	myQue() {};
	~myQue() {};

public:
	void push(int num);
	int pop();
	void list();
	int size();
	int empty();
	int front();
	int back();

};

void myQue::push(int num) {
	count++;
	Node* newNode = new Node;
	newNode->data = num;
	newNode->next = NULL;
	if (head == NULL) {
		// 첫 번째 노드를 head가 가리키게 함
		head = newNode;
		tail = head;
	}
	else {
		// 새로 들어온 노드가 현재의 tail을 가리키게 함
		// tail <- newNode
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

int myQue::pop() {
	if (count == 0) 
		return -1;
	else {
		count--;
		Node* rTemp = head;
		int tmp = head->data;
		head = rTemp->next;
		delete(rTemp);
		return tmp;
	}
}

int myQue::size() {
	return myQue::count;
}

void myQue::list() {
	if (count == 0)
		cout << "Not found data\n";
	else {
		Node* tempNode = new Node;
		tempNode = head;
		while (tempNode != NULL) {
			cout << tempNode->data << " ";
			tempNode = tempNode->next;
		}
	}
}

int myQue::empty() {
	if (myQue::count > 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int myQue::front() {
	if (count == 0) {
		return -1;
	}
	else {
		return head->data;
	}
}

int myQue::back() {
	if (count == 0)
		return -1;
	else 
		return tail->data;
}

int main() {
	myQue q;
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
		else if (s == "front")
			ans.push_back(q.front());
		else if (s == "back")
			ans.push_back(q.back());
		n--;
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

}