#include <bits/stdc++.h>
using namespace std;

pair<int,int> m[100001];

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        m[i].first = m1 * 100 + d1;
        m[i].second = m2 * 100 + d2;
    }
    sort(m, m + n,cmp);
    int ans = 0;
    int j = 0;
    int mx = 301;
    while(mx <= 1130)  {
        if(j == n) break;
        int tmp = mx;
        if(m[j].first > mx) break;
        while(m[j].first <= mx) {
            if(tmp < m[j].second) {
                tmp = m[j].second;
            }
            j++;
            if(j == n) break;
        }
        ans++;
        mx = tmp;
    }
    if(mx > 1130) cout << ans;
    else cout << 0;
}
