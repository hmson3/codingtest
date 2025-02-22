#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int mn = 100;
    for (int i = 0; i < 7; i++) {
        int n;
        cin >> n;
        if(n % 2 == 0) continue;
        ans += n;
        if(mn > n) mn = n; 
    }
    if(ans) cout << ans << '\n' << mn;
    else cout << -1;
}
