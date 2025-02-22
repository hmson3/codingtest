#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S1,S3("");
    int T = 0;
    cin >> S1;
    for (int i = 0; i < S1.length(); i++) {
        S3 += S1[S1.length()-1-i];
    }
    cout << (S1 == S3);
    
    return 0;
}