#include <bits/stdc++.h>
using namespace std;

int main() {
    map <string, string> mp;
    
    mp["CU"] = "see you";
    mp[":-)"] = "I’m happy";
    mp[":-("] = "I’m unhappy";
    mp[";-)"] = "wink";
    mp[":-P"] = "stick out my tongue";
    mp["(~.~)"] = "sleepy";
    mp["TA"] = "totally awesome";
    mp["CCC"] = "Canadian Computing Competition";
    mp["CUZ"] = "because";
    mp["TY"] = "thank-you";
    mp["YW"] = "you’re welcome";
    mp["TTYL"] = "talk to you later";
    string s;
    while (cin >> s) {
        if (mp.find(s) != mp.end())
            cout << mp[s] << endl;
        else
            cout << s << endl;
   }
}