#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S("");
    int T = 1;
    getline(cin, S);
    if (S[0] == ' ') T = 0;
    for (int i = 0; i < S.length(); i++) {

        if (S[i] == ' ') {
            T++;
        }    
    }
    if (S[S.length()-1] == ' ') T--;
    cout << T;
    
    return 0;
}