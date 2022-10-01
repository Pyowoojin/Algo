#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = 0;
    string s; s = to_string(x);
    int sum = 0;
    
    for(int i = 0; i<s.length(); i++){
        sum+=s[i]-'0';
    }
    
    if(x % sum == 0)
        answer = true;
    else
        answer = false;
    
    return answer;
}