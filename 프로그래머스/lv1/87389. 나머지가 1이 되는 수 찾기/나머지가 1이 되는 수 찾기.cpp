#include <string>
#include <vector>

using namespace std;

bool arr[1000001] = {false, } ;

void era(int n){
    arr[0] = arr[1] = true;
    for(int i = 2; i * i <= n; i++){
        if(!arr[i]){
            for(int j = i + i; j <=n; j+=i)
                arr[j] = true;
        }
    }
}

int solution(int n) {
    for(int i = 2; i < n; i++){
        if(n% i == 1)
        {
            return i;
        }
    }
}