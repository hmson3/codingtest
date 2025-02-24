#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s; 
        cin >> s;
        int score = 0;
        int ans = 0;
        for(char c : s) {
            if(c == 'O') ans += ++score;
            else score = 0; 
        }
        cout << ans << '\n';
    }
}