#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> vc(n);
    for(int i = 0; i<n; i++){
        cin >> vc[i];
    }
    
    sort(vc.begin(), vc.end());
    for(auto i : vc)
        cout << i << '\n';
}