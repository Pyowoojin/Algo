#include <string>
#include <vector>
using namespace std;

int ans = 0;
int cnt = 0;
string str = "AEIOU";
string targetWord;

void dfs(string word){
    if(word.length() > 5){
        return;
    }
    cnt++;
    
    if(word == targetWord){
        ans = cnt;
        return;
    }
    
    for(int i = 0; i < 5; i++){
        dfs(word + str[i]);
    }
}

int solution(string word) {
    targetWord = word;
    int answer = 0;
    dfs("");
    answer = ans;
    
    return answer - 1;
}