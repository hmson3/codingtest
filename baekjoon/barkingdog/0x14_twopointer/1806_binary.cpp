#include <bits/stdc++.h>
using namespace std;

long long summ;
long long sum[100001];
int n,s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    int xxx;
    for (int i = 1; i <= n; i++) {
        cin >> xxx;
        summ += xxx;
        sum[i] = summ;
    }
    int ans = 100001;
    for(int st = 0; st < n; st++) {
        int en = lower_bound(sum,sum+n+1,sum[st]+s) - sum;
        if(en == n+1) break;
        ans = min(ans,en-st);
    }
    if(ans == 100001) cout << 0;
    else  cout << ans;
}