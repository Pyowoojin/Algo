#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool visitedAt[101][101];
int Dist[101][101];

bool IsValid(vector <vector<char>>& tile, int nX, int nY){
    if(nX > -1 && nY > -1 && nX < tile.size() && nY < tile[0].size()){
        if(tile[nX][nY] != 'D'){
            return true;
        }
    }
    return false;
}

void bfs(vector <vector<char>>& tile, int startX, int startY){
    pair <int, int> origin;
    queue <pair <int, int>> que;
    que.push({startX, startY});
    visitedAt[startX][startY] = true;
    
    while(!que.empty()){
        origin = que.front(); que.pop();
        
        for(int i = 0; i < 4; i++){
            pair <int, int> temp = origin;
            while(true){
                int nX = dx[i] + temp.first;
                int nY = dy[i] + temp.second;
                
                if(!IsValid(tile, nX, nY))
                    break;
                
                temp.first = nX;
                temp.second = nY;
            }
            // 한 번의 이동이 완료되었음
            // 현재 위치에 도달한 적이 없다면 Dist 갱신 후 큐에 넣어준다.
            // (해당 위치부터 다시 시작!)
            if(visitedAt[temp.first][temp.second] == false){
                Dist[temp.first][temp.second] = Dist[origin.first][origin.second] + 1;
                que.push({temp.first, temp.second});
                visitedAt[temp.first][temp.second] = true;
            }
            // 현재 위치에 도달한 적이 있다면, Dist를 확인한다. 짧다면 갱신해준다.
            else{
                if(Dist[temp.first][temp.second] > Dist[origin.first][origin.second] + 1){
                    Dist[temp.first][temp.second] = Dist[origin.first][origin.second] + 1;
                    que.push({temp.first, temp.second});
                }
            }
        }
    }
}

int solution(vector<string> board) {
    int answer = -1;
    vector <vector <char>> tile(board.size());
    
    int startX = 0, startY = 0;
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            tile[i].push_back(board[i][j]);
            if(board[i][j] == 'R'){
                startX = i;
                startY = j;
            }
        }
    }
    
    bfs(tile, startX , startY);
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'G')
                answer = Dist[i][j] != 0 ? Dist[i][j] : -1;
        }
    }
    
    
    return answer;
}