#include <bits/stdc++.h>
using namespace std;

int main() {
	int hour, minute, second;
	cin >> hour >> minute >> second;

	int needTime; cin >> needTime;

	second += needTime;
	int upperMin = second / 60;
	second = second % 60;

	minute += upperMin;
	int upperHour = minute / 60;
	minute = minute % 60;

	cout << (hour + upperHour) % 24 << " " << minute << " " << second;
}