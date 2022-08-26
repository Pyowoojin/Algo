#include <iostream>
#include <string>
using namespace std;

int main() {
	int result, one, ten, hun;
	char n1[5], n2[5];

	cin >> n1 >> n2;
	
	int num1 = atoi(n1);
	int num2 = atoi(n2);
	one = n2[2] - '0';
	ten = n2[1] - '0';
	hun = n2[0] - '0';

	cout << num1 * one << endl << num1 * ten << endl << num1* hun << endl;
	cout << num1 * num2;
}