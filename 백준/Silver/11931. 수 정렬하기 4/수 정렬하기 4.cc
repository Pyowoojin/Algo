#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector <int> vc;
    
    for(int i = 0; i<n; i++){
        int c; cin >> c;
        vc.push_back(c);
    }
    sort(vc.begin(), vc.end(), greater<>());
    
    for(auto i : vc)
        cout << i << '\n';
}