#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s  = {};
    int n;
    cin >> n;
    unsigned int ans = 0;
    for(int i = 0; i < n; i++) {
        int r;
        cin >> r;
        if(s.empty()) {
            s.push(r);
            continue;
        }
        while(r >= s.top()) {
            s.pop();
            if(s.empty()) break;
        }
        ans += s.size();
        s.push(r);
    }
    cout << ans;
}