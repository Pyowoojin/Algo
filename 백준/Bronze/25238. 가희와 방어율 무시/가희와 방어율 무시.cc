#include <iostream>
using namespace std;

int main(){
    double a, b; cin >> a >> b;
    double total;
    total = a - (0.01 * b * a);
    
    if(total >= 100)
        cout << "0";
    else
        cout << "1";
}