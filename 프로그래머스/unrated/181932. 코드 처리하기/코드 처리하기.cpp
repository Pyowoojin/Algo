#include <bits/stdc++.h>
using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = false;
    for(int i = 0; i < code.length(); i++){
        if(!mode){
            if(code[i] != '1'){
                if(i % 2 == 0){
                    answer+=code[i];
                }
            }
            else{
                mode = !mode;
            }
        }
        else{
            if(code[i] != '1'){
                if(i%2 == 1){
                    answer+=code[i];
                }
            }
            else{
                mode = !mode;
            }
        }
    }
    if(answer.length() == 0)
        answer = "EMPTY";
    return answer;
}