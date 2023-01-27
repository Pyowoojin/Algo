#include <bits/stdc++.h>
using namespace std;

bool isChanged[4];

void init() {
    for (int i = 0; i < 4; i++)
        isChanged[i] = false;
}

void rotation(vector <string>& wheel, int wheelNum, int dir, string originStatus, int k, int toRight) {
    // 1 ~ 4 범위를 넘어갈 경우 종료
    if ((wheel.size() == wheelNum) || (wheelNum < 0))
        return;

    // 이미 변화한 톱니바퀴라면 재귀 종료
    if (isChanged[wheelNum])
        return;
    string storeString = wheel[wheelNum];

    // toRight이 1이면 이전 톱니의 2번과 현재 톱니의 6번을 비교
    // toRight이 2이면 이전 톱니의 6번과 현재 톱니의 2번을 비교
    // toRight이 3이면 첫 변화

    if (k > 0) {
        // N - S 로 다른 극이라면 톱니바퀴 회전
        if (toRight == 1) {
            if (originStatus[2] != wheel[wheelNum][6]) {
                if (dir == 1) {
                    // 마지막 숫자를 빼고 맨 앞에 집어넣어준다.
                    char last = wheel[wheelNum][7];
                    wheel[wheelNum].pop_back();
                    wheel[wheelNum].insert(0, 1, last);
                }
                // 반시계 방향 회전
                else {
                    // 맨 앞 숫자를 빼고 맨 뒤로 넣어준다.
                    char last = wheel[wheelNum][0];
                    wheel[wheelNum].erase(0, 1);
                    wheel[wheelNum].push_back(last);
                }
            }
            // 같은 극이라 회전이 이루어지지 않았다면, 연쇄 작용을 종료함 ★
            else {
                return;
            }
        }
        else if (toRight == 2) {
            if (originStatus[6] != wheel[wheelNum][2]) {
                if (dir == 1) {
                    // 마지막 숫자를 빼고 맨 앞에 집어넣어준다.
                    char last = wheel[wheelNum][7];
                    wheel[wheelNum].pop_back();
                    wheel[wheelNum].insert(0, 1, last);
                }
                // 반시계 방향 회전
                else {
                    // 맨 앞 숫자를 빼고 맨 뒤로 넣어준다.
                    char last = wheel[wheelNum][0];
                    wheel[wheelNum].erase(0, 1);
                    wheel[wheelNum].push_back(last);
                }
            }
            else {
                return;
            }
        }
    }
    else
    {
        if (dir == 1) {
            // 마지막 숫자를 빼고 맨 앞에 집어넣어준다.
            char last = wheel[wheelNum][7];
            wheel[wheelNum].pop_back();
            wheel[wheelNum].insert(0, 1, last);
        }
        // 반시계 방향 회전
        else {
            // 맨 앞 숫자를 빼고 맨 뒤로 넣어준다.
            char last = wheel[wheelNum][0];
            wheel[wheelNum].erase(0, 1);
            wheel[wheelNum].push_back(last);
        }
    }

    isChanged[wheelNum] = true;

    // 재귀문 실행
    // 왼쪽 이동 = 1, 오른쪽 이동 = 2
    rotation(wheel, wheelNum + 1, -1 * dir, storeString, ++k, 1);
    rotation(wheel, wheelNum - 1, -1 * dir, storeString, ++k, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <string> wheel(4);

    for (int i = 0; i < 4; i++) {
        string s; cin >> s;
        wheel[i] = s;
    }

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int c, dir; cin >> c >> dir;
        rotation(wheel, c - 1, dir, "", 0, 3);
        init();
    }

    int total = 0;

    for (int i = 1; i < 5; i++) {
        if (wheel[i - 1][0] == '1') {
            total += pow(2, i - 1);
        }
    }
    cout << total;

}