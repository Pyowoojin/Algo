#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	/*
	* 
	* Q. 수직선 위에 선분을 여러개 그린다.
	* 선분은 겹치게 그려질 수도 있다.
	* 모두 그렸을 때의 선분의 총 합은?
	*/

	/*
	* 선분의 개수 N이 주어진다.
	* 좌표를 나타내는 정수쌍 (x,y)가 주어짐
	*/

	int n; cin >> n;

	vector <pair <int, int>> vc(n);

	for (int i = 0; i < n; i++) {
		cin >> vc[i].first;
		cin >> vc[i].second;
	}
	int min = vc[0].first;
	int max = vc[0].second;

	long long total = 0;

	for (int i = 1; i < n; i++) {
		// 시작점이 겹치는 경우 -> 선분을 확장 or 선분에 포함시키기
		if (min <= vc[i].first && vc[i].first <= max) {
			// 기존 선분보다 긴 경우
			if (max <= vc[i].second) {
				max = vc[i].second;
			}
		}
		// 아예 다른 선분인 경우 -> 기존 값을 더해주고 max min 새로 설정
		else if (max < vc[i].first) {
			total += max - min;
			min = vc[i].first;
			max = vc[i].second;
		}
	}

	cout << total + max - min;

}