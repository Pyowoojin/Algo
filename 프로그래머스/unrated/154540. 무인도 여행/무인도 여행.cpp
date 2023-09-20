#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(vector <vector<int>>& maps, vector <vector<int>>& visited, int x, int y){
    visited[x][y] = true;
    queue <pair <int, int>> que;
    que.push({x,y});
    pair <int, int> temp;
    int cnt = maps[x][y];
    
    while(!que.empty()){
        temp = que.front();
        que.pop();
        
        for(int i = 0; i < 4; i++){
            int nX = dx[i] + temp.first;
            int nY = dy[i] + temp.second;
            
            if(nX > -1 && nX < maps.size() && nY > -1 && nY < maps[0].size()){
                if(visited[nX][nY] == 0 && maps[nX][nY] != 0){
                    visited[nX][nY] = 1;
                    que.push({nX, nY});
                    cnt+= maps[nX][nY];
                }
            }
        }
    }
    
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    vector <vector <int>> newMap(maps.size(), vector <int>(maps[0].size()));
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(maps[i][j] == 'X'){
                newMap[i][j] = 0;
            }
            else{
                newMap[i][j] = maps[i][j] -'0';
            }
        }
    }
    vector <vector <int>> visited(newMap.size(), vector <int>(newMap[0].size(), 0));

    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(visited[i][j] == 0 && maps[i][j] != 'X'){
                answer.push_back(bfs(newMap, visited, i, j));
            }
        }
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    sort(answer.begin(), answer.end());    
    return answer;
}