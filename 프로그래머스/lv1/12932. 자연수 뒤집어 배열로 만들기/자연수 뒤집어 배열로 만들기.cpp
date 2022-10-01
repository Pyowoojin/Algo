#include <bits/stdc++.h>

using namespace std;

vector<int> solution(long long n) {
    string s; s = to_string(n);
    vector<int> answer;
    for(int i = s.length() -1; i > -1; i--){
        answer.push_back(s[i]-'0');
    }
    
    return answer;
}