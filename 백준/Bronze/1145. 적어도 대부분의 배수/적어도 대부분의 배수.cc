#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector <int> vc(5);

    for (int i = 0; i < 5; i++) {
        cin >> vc[i];
    }

    int ans = 1;
    int k = 1;

    while (1) {
        
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (k % vc[i] == 0) {
                cnt++;
            }
        }

        if (cnt >= 3) {
            ans = k;
            break;
        }

        k++;
    }

    cout << ans;

}
