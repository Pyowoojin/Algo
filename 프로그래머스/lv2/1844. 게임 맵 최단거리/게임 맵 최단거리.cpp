#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 0은 벽, 1은 이동 가능

template <typename T>
void init(vector <T> &maps, int param){
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(param == 0)
                maps[i][j] = 0;
            else
                maps[i][j] = 1;
        }
    }
}

template <typename T>
int bfs(vector <T> &visited, vector<T> &maps, vector <T> &cost, int i, int j){
    int ans = -1;
    
    pair <int, int> tmp;
    queue <pair <int, int>> q;
    q.push({i,j});
    
    while(!q.empty()){
        tmp = q.front(); q.pop();
        
        for(int k = 0; k < 4; k++){
            int nX = tmp.first + dx[k];
            int nY = tmp.second + dy[k];
            
            if(nX > -1 && nY > -1 && nX < maps.size() && nY < maps[0].size()){
                if(visited[nX][nY] == 0 && maps[nX][nY] == 1){
                    visited[nX][nY] = 1;
                    q.push({nX,nY});
                    cost[nX][nY] = cost[tmp.first][tmp.second] + 1;
                    if(nX == maps.size() -1 && nY == maps[0].size() -1)
                        ans = cost[nX][nY];
                }
            }
            
        }
        
    }
    
    return ans;
}

int solution(vector<vector<int>> maps)
{
    vector <vector<int>> visit(maps);
    vector <vector<int>> cost(maps);
    init(visit, 0);
    init(cost, 1);
    
    int answer = 0;
    answer = bfs(visit, maps, cost, 0, 0);
    
    return answer;
}