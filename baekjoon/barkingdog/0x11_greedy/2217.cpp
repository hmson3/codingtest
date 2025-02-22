#include <bits/stdc++.h>
using namespace std;

int a[100001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    int ans = a[n-1];
    for (int i = n-1; i >= 0; i--) {
        ans = max(ans,a[i]*(n-i));
    }
    
    cout << ans;
}