#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool low_arr[26];
bool upper_arr[26];
bool spacebar;

// A = 65, a = 97
string solution(string my_string) {
    string answer = "";
    for(int i = 0; i< my_string.length(); i++){
        int num = my_string[i] -'0';
       // 공백일 경우
        if(num == -16){
            if(!spacebar){
                spacebar = true;
                answer+= " ";
            }
        }
        // 소문자일 경우
        else if(num >= 49 && num <= 75){
            if(!low_arr[num - 49]){
                low_arr[num - 49] = true;
                answer+= my_string[i];
            }
        }
        else if(num >= 17 && num <= 43){
            if(!upper_arr[num - 17]){
                upper_arr[num-17] = true;
                answer+= my_string[i];
            }
        }
    }
    
    return answer;
}