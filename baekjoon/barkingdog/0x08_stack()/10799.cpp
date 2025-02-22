#include <bits/stdc++.h>
using namespace std;

int ans,lazer;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<int> t;
    for(auto c : s) {
        if(c == '(') {
            lazer = 0;
            t.push(c);
        }
        else {
            if(lazer) {
                t.pop();
                ans += 1;
            }
            else {
                t.pop();
                ans += t.size();
                lazer++;
            }
        }
    }
    cout << ans;
}