#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    bool answer = false;
    stack <char> stk;
    
    if(s.length() % 2 == 0){
        for(int i = 0; i < s.length(); i++){
            if(stk.size() > 0){
                // 두 개가 같다면 지워주기
                if(stk.top() == s[i]){
                    stk.pop();
                }
                // 같지 않다면 그냥 넣어주기
                else{
                    stk.push(s[i]);
                }
            }
            else{
                stk.push(s[i]);
            }
        }
        
        if(stk.size() == 0){
            answer = true;
        }
    }
    
    return answer;
}