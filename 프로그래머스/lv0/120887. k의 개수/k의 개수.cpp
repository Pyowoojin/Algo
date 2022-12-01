#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for(int a= i; a <= j; a++){
        string s = to_string(a);
        for(int l = 0; l < s.length(); l++){
            if(s[l] == k+'0')
                answer++;
        }
        
    }
    return answer;
}