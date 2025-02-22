#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S1,S2,S3("");
    int T,R;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> R >> S1;
        for (int j = 0; j < S1.length(); j++) {
            for (int k = 0; k < R; k++) {
                S2 += S1[j];
            }
        }
        cout << S2 << "\n";
        S2 = "";
    }
    
    return 0;
}