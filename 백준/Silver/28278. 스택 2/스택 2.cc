#include <bits/stdc++.h>
using namespace std;

int StackArray[1000001];

class Customstack {
public :
	Customstack() {
		stackSize = 0;
		stackPointer = 0;
	};

	int GetStackSize();
	bool IsEmpty();
	void InsertData(int data);
	void PopAndPrint();
	void Print();
private :
	int stackSize = 0;
	int stackPointer = 0;
};

int Customstack::GetStackSize()
{
	return stackSize;
}

// 비었다면 true 리턴
bool Customstack::IsEmpty()
{
	return (GetStackSize() <= 0);
}

void Customstack::InsertData(int data)
{
	StackArray[stackPointer] = data;
	stackPointer++;
	stackSize++;
}

void Customstack::PopAndPrint()
{
	if (!IsEmpty()) {
		stackPointer--;
		cout << StackArray[stackPointer] << '\n';
		stackSize--;
	}
	else
		cout << "-1\n";
}

void Customstack::Print()
{
	if (!IsEmpty())
		cout << StackArray[stackPointer - 1] << "\n";
	else
		cout << "-1\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	Customstack stk{};
	while (n--) {
		int c; cin >> c;
		if (c == 1) {
			int k; cin >> k;
			stk.InsertData(k);
		}
		else if (c == 2) {
			stk.PopAndPrint();
		}
		else if (c == 3) {
			cout << stk.GetStackSize() << '\n';
		}
		else if (c == 4) {
			cout << stk.IsEmpty() << '\n';
		}
		else if (c == 5) {
			stk.Print();
		}
	}
}
