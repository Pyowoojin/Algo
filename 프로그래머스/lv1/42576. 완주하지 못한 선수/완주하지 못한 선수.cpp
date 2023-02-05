#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string ans = "";
    unordered_map <string, int> mp;
    
    for(int i = 0; i< participant.size(); i++){
        mp[participant[i]] += 1;
    }
    
    for(int i = 0; i< completion.size(); i++){
        if(mp.find(completion[i]) != mp.end()){
            mp[completion[i]] -=1;
        }
    }
    
    for(auto i = mp.begin(); i != mp.end(); i++){
        if(i->second !=0)
            ans = i->first;
    }
    
    return ans;
}