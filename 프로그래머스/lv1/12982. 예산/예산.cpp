#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    int answer = 0;
    
    for(int i = 0; i<d.size(); i++){
        if(d[i] > budget)
            break;
        budget-=d[i];
        answer++;
    }
    
    return answer;
}