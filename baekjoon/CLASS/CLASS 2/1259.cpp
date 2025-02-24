#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        string s;
        cin >> s;
        if(s =="0") break;
        int n = s.size();
        bool ck = 1;
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n-1-i]) ck=0;
        }
        if(ck) cout << "yes" << '\n';
        else cout << "no" << '\n';

    }
}