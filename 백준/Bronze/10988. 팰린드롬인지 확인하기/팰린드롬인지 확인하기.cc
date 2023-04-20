#include <bits/stdc++.h>
int main() {
	std::string s; std::cin >> s;
	bool ans = true;
	for (int i = 0, j = s.size() - 1; i < s.size(); i++, j--)
		if (s[i] != s[j])
			ans = false;
	std::cout << ans;}