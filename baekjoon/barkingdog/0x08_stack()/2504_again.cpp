#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<pair<char,int>> s;
    int ans = 0;
    for(auto c : str) {
        if(c == '(') {
            s.push({c,0});
        }
        else if(c == ')') {
            if(s.empty() || s.top().first == '[') {cout << 0; return 0;}
            int tmp = 2;
            if(s.top().second) tmp = 2*s.top().second;
            s.pop();
            if(s.empty()) {ans += tmp; continue;}
            s.top().second += tmp;
        }
        else if(c == '[') {
            s.push({c,0});
        }
        else if(c == ']') {
            if(s.empty() || s.top().first == '(') {cout << 0; return 0;}
            int tmp = 3;
            if(s.top().second) tmp = 3*s.top().second;
            s.pop();
            if(s.empty()) {ans += tmp; continue;}
            s.top().second += tmp;
        }
    }
    cout << ans;
}