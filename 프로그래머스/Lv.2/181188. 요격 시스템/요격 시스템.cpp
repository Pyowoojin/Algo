#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end());
    
    int start = targets[0][1];
    int end = 0;
    
    for(int i = 1; i < targets.size(); i++){
        if(start <= targets[i][0]){
            answer++;
            start = targets[i][1];
            continue;
        }
        
        if(start > targets[i][1]){
            start = targets[i][1];
        }
    }
    
    return answer;
}