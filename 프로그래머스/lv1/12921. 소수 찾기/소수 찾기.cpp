#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

bool arr[1000001];

using namespace std;

void isPrime(int n){
    arr[0] = arr[1] = true;
    
    for(int i = 2; i<=sqrt(n); i++){
        if(arr[i] == false){
            for(int j = i+i; j<=n; j+=i){
                arr[j] = true;
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    isPrime(n);
    
    for(int i = 2; i<=n; i++){
        if(!arr[i]){
            answer++;
        }
    }
    
    return answer;
}