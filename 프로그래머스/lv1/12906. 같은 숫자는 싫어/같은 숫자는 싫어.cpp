#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    queue <int> q;
    
    for(int i= 0; i<arr.size(); i++){
        q.push(arr[i]);
    }
    arr.clear();
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        arr.push_back(now);
        while((q.front() == now) && !q.empty()){
            q.pop();
        }
    }
    
    
    return arr;
}