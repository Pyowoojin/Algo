#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    cin >> number;
    int numb = number;
    vector <int> digits;
    int num_digits = 0;

    // 숫자를 자릿수별로 나누기
    while (numb > 3) {

        bool ans = true;
        number = numb;
        while (number > 0) {
            if ((number % 10 != 4) && (number % 10 != 7)) {
                ans = false;
                break;
            }

            number /= 10;
        }

        if (ans == true)
            break;
        numb--;
    }

    cout << numb;
}
