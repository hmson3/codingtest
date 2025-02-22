#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> t;
    int check = 0;
    int ans = 0;
    int num = 1;
    for(int i = 0; i < s.size(); i++){ {
        if(s[i] == '(') {
            num *= 2;
            t.push(s[i]);
        }    
        if(s[i] == '[') {
            num *= 3;
            t.push(s[i]);
        }
        else if(s[i] == ')') {
            if(t.empty() || t.top() != '(') {
                cout << 0;
                return 0;
            }
            if(s[i-1] == '(') ans += num;
            t.pop();
            num /= 2;
        }
        else if(s[i] == ']') {
            if(t.empty() || t.top() != '[') {
                cout << 0;
                return 0;
            } 
            if(s[i-1] == '[') ans += num;
            t.pop();
            num /= 3;
        }

        }
    }
    if(t.empty()) cout << ans;
    else cout << 0;
}