#include <bits/stdc++.h>
using namespace std;

int arr[26];

void init(){
    for(int i = 0; i < 26; i++){
        arr[i] = 10000;
    }
}
// 65

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    init();
    for(int i = 0; i < keymap.size(); i++){
        for(int j = 0; j < keymap[i].length(); j++){
            char c = keymap[i][j];
            if(arr[c-65] > j + 1){
                arr[c-65] = j+1;
            }
        }
    }
    
    for(int i = 0; i <targets.size(); i++){
        int sum = 0;
        for(int j = 0; j < targets[i].length(); j++){
            char c = targets[i][j];
            if(arr[c-65] == 10000){
                sum = -1;
                break;
            }
            else{
                sum += arr[c - 65];   
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}