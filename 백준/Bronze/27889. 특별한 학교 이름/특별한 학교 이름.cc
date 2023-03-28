#include <bits/stdc++.h>
using namespace std;

int main(){
    map <string, string> mp;
    string s1 = "North London Collegiate School";
    string s2 = "Branksome Hall Asia";
    string s3 = "Korea International School";
    string s4 = "St. Johnsbury Academy";
    mp.insert({"NLCS", s1});
    mp.insert({"BHA", s2});
    mp.insert({"KIS", s3});
    mp.insert({"SJA", s4});

    
    string s; cin >> s;
    cout << mp[s];
}