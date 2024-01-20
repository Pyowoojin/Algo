#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector <pair <int, int>> bookList;
    
    vector <vector <pair <int, int>>> vc(1000);
 
    for(int i = 0; i < book_time.size(); i++){
        int startHour = stoi(book_time[i][0].substr(0,2));
        int startMin = stoi(book_time[i][0].substr(3,2));

        int startTime = startHour * 60 + startMin;

        int endHour = stoi(book_time[i][1].substr(0,2));
        int endMin = stoi(book_time[i][1].substr(3,2));
        
        int endTime = endHour * 60 + endMin;
        
        bookList.push_back({startTime, endTime+10});
    }
    
    sort(bookList.begin(), bookList.end());
    
    
    for(int i = 0; i < bookList.size(); i++){
        
        // 방 1000개를 확인할 것이다.
        for(int j = 0; j < 1000; j++){
            // 해당 방이 비어있는 방이면 방에 배정해준다.
            if(vc[j].size() == 0){
                vc[j].push_back({bookList[i].first, bookList[i].second});
                break;
            }
            // 현재 방의 마지막 퇴실 시간보다 현재 예약의 입실시간이 더 이전이라면 다음 방으로
            if(vc[j][vc[j].size()-1].second > bookList[i].first){
                continue;
            }
            else if(vc[j][vc[j].size()-1].second <= bookList[i].first){
                vc[j].push_back({bookList[i].first, bookList[i].second});
                break;
            }
        }
    }
    
    for(int l = 0; l < 1000; l++){
        if(vc[l].size() > 0){
            cout << l << "번 방 : ";
            for(int j = 0; j < vc[l].size(); j++){
                cout << vc[l][j].second << " ~ " << vc[l][j].first << " / ";
            }
            cout << endl;
            answer++;
        }
    }
    
    return answer;
}