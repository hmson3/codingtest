#include <bits/stdc++.h>
using namespace std;

int a[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = a[0];
    int dp = a[0];
    for (int i = 1; i < n; i++) {
        dp += a[i];
        ans += dp;
    }

    cout << ans;
}