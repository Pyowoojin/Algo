#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    long long cal = 0;
    for(int i = 0; i< n; i++){
        long long a; cin >> a;
        cal += a;
    }
    cout << cal;
}