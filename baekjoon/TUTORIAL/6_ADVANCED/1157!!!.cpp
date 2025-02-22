#include <iostream>
#include <string>
using namespace std;

int main()
{

    string S1("");
    int T[26] = {};
    int M = 0; // int M,R = 0; M 변수 초기화 안됨
    int R = 0;
    char C = 0;
    
    cin >> S1;
    for (int i = 0; i < S1.length(); i++) {
        if (S1[i] >= 'a') T[S1[i] - 97]++;
        else T[S1[i] - 65]++;
    }

    for (int i = 0; i < 26; i++) {
        if (T[i] > M) {
            M = T[i];
            C = i + 65;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (T[i] ==  M) {
            R++;
        }
    }

    if (R-1) C = '?';

    cout << C;
    
    return 0;
}