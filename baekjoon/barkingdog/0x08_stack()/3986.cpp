#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;

    int ans = 0;

    while(n--) {
        cin >> s;
        stack<char> t = {};

        int a = 0;
        int b = 0;
        int check = 0;

        for(char c : s) {
            if(c == 'A') {
                if(a == 0) {
                    t.push(c);
                    a++;
                }
                else if(t.top() == c) {
                    a--;
                    t.pop();
                    check--;
                }
                else {
                    a++;
                    t.push(c);
                    check++;
                }                    
            }
            else if(c == 'B') {
                if(b == 0) {
                    t.push(c);
                    b++;
                }
                else if(t.top() == c) {
                    b--;
                    t.pop();
                    check--;
                }
                else {
                    b++;
                    t.push(c);
                    check++;
                }                    
            }
            
        }
        if(check <= 0 && t.empty()) ans++;
    }
    cout << ans;

}