#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

pair <int, int> ParkSimulate(vector <string>& park, pair <int, int>& curLoc, int dir, int distance){
    pair <int, int> tempLoc = curLoc;
    
    for(int i = 0; i < distance; i++){
        int nX = dx[dir] + tempLoc.first;
        int nY = dy[dir] + tempLoc.second;
        
        // 이 경우에는 이번 명령을 무시할 것임
        if(park[nX][nY] == 'X' ||
           (nX < 0 || nY < 0 || nX >= park.size() || nY >= park[0].size())){
            return curLoc;
        }
        else{
            tempLoc.first = nX, tempLoc.second = nY;
        }
    }
    
    curLoc = tempLoc;
    
    return curLoc;
}

pair <int, int> FindStartLocation(vector <string>& vc){
    pair <int, int> loc;
    for(int i = 0; i < vc.size(); i++){
        for(int j = 0; j < vc[0].size(); j++){
            if(vc[i][j] == 'S'){
                loc = {i,j};
            }
        }
    }
    return loc;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    char dir = '0';
    int dist = 0;
    
    pair <int, int> curLoc = FindStartLocation(park);
    
    for(int i = 0; i < routes.size(); i++){
        dir = routes[i][0];
        dist = routes[i][2] - '0';
        
        //cout << curLoc.first << " " << curLoc.second << endl;
        
        if(dir == 'E'){
            ParkSimulate(park, curLoc, 1, dist);
        }
        else if(dir == 'W'){
            ParkSimulate(park, curLoc, 3, dist);
        }
        else if(dir == 'N'){
            ParkSimulate(park, curLoc, 0, dist);
        }
        else
        {
            ParkSimulate(park, curLoc, 2, dist);
        }
    }
    
    answer.push_back(curLoc.first);
    answer.push_back(curLoc.second);
    
    return answer;
}