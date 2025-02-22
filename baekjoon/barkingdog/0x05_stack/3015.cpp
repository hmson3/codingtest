#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> s = {};

    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        if(s.empty()) {
            s.push({r,1});
            continue;
        }
        int ho = 1;
        while (!s.empty() && r >= s.top().first) {
            if(s.top().first == r) 
                ho = s.top().second+1;
            ans += s.top().second;
            s.pop();
        }
        if(!s.empty()) ans++;
        s.push({r,ho});
    }
    cout << ans;
}