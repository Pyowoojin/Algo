#include <iostream>
#include <numeric>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
	int tc; cin >> tc;



	while (tc--) {
		unordered_map <string, int> mp;
		int i = 16;
		while (i--) {
			string first, second;
			cin >> first >> second;
			cin.ignore();
			int ifirst = 0, isecond = 0;
			cin >> ifirst >> isecond;
			cin.ignore();

			string pushStr, popStr;
			if (ifirst > isecond) {
				pushStr = first;
				popStr = second;
			}
			else {
				pushStr = second;
				popStr = first;
			}

			mp[pushStr]++;

		}

		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			if (i->second == 4) {
				cout << i->first << endl;
				break;
			}
		}
	}
	
}