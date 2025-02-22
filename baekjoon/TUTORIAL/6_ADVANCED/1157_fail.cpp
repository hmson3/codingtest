// 답은 맞지만 시간초과
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S1("");
    int T = 0;
    int M = 0;
    char C = 0;
    cin >> S1;
    for (int i = 0; i < S1.length(); i++) {
        for (int j = 0; j < S1.length(); j++) {
            if (S1[i] == S1[j] || S1[i] + 32 == S1[j] || S1[i] - 32 == S1[j] ) T++;
        }
        if (M == T && S1[i] != C && S1[i] != C + 32) C = '?';
        else if (M < T) {
            M = T;
            if (S1[i] >= 'a') C = S1[i] - 32;
            else C = S1[i];
        }
        T = 0;
    }   
    cout << C;
    
    return 0;
}