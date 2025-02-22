#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        stack<pair<int, int>> s = {};
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;
            if (s.empty()) {
                s.push({i, r});
                continue;
            }
            while (!s.empty() && r < s.top().second) {
                long long hi = s.top().second;
                s.pop();
                long long wid = i;
                if (!s.empty()) wid = i - s.top().first - 1;
                long long mx = hi * wid;
                ans = max(mx, ans);
            }
            s.push({i, r});
        }
        while (!s.empty()) {
            long long hi = s.top().second;
            s.pop();
            long long wid = n;
            if (!s.empty()) wid = n - s.top().first - 1;
            long long mx = hi * wid;
            ans = max(mx, ans);
        }
        cout << ans << '\n';
    }
}