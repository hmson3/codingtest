#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        deque<pair<int, int>> q;
        int a[10] = {};
        for (int i = 0; i < n; i++) {
            int iii;
            cin >> iii;
            a[iii]++;
            q.push_back({iii, i});
        }
        int ans = 1;
        int ck = 0;
        for (int i = 9; i > 0; i--) {
            while (a[i]--) {
                while (q.front().first != i) {
                    q.push_back(q.front());
                    q.pop_front();
                }
                if (q.front().second == m) {
                    cout << ans << '\n';
                    ck = 1;
                    break;
                } else {
                    q.pop_front();
                    ans++;
                }
            }
            if (ck) break;
        }
    }
}