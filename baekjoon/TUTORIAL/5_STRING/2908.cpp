#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S1,S2,S3("");
    int T = 0;
    cin >> S1 >> S2;
    for (int i = 0; i < S1.length(); i++) {
        S3 += S1[S1.length()-1-i];
    }
    S1 = S3;
    S3 = "";
    for (int i = 0; i < S2.length(); i++) {
        S3 += S2[S2.length()-1-i];
    }
    S2 = S3;
    if(stoi(S1) > stoi(S2)) cout << S1;
    else cout << S2;
    
    return 0;
}