#include <bits/stdc++.h>
using namespace std;

int a[100000];
int n,m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    int st = 0; 
    int en = 0;
    int ans = 2000000001;
    for(int st = 0; st < n; st++) {
        int en = lower_bound(a,a+n,a[st]+m) - a;
        if(en == n) break;
        ans = min(ans,a[en]-a[st]);
    }
    cout << ans;
}