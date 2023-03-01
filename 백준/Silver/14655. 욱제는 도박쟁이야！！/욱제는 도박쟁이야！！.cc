#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector <int> first;
    vector <int> second;

    int total = 0;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c < 0) {
            total += (-1 * c);
        }
        else
            total += c;
    }
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        if (c < 0) {
            total += (-1 * c);
        }
        else
            total += c;
    }

    cout << total;

}