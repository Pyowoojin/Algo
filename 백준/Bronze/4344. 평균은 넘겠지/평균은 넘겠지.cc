#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int mean;
	cin >> n;
	vector <float> result(n);

	for (int i = 0; i < n; i++) {
		int sum = 0;
		int _count = 0;
		int temp;
		cin >> temp;
		vector <int> tc(temp);

		for (int j = 0; j < temp; j++) {
			int x;
			cin >> x;
			sum += x;
			tc[j] = x;
		}
		mean = sum / temp;
		for (int k = 0; k < temp; k++) {
			if (tc[k] > mean) {
				_count++;
			}
		}
		float ratio = (float(_count) / float(temp)) * 100;
		result[i] = ratio;
	}

	for (int i = 0; i < n; i++) {
		cout << fixed;
		cout.precision(3);
		cout << result[i] << "%" << endl;
	}
}