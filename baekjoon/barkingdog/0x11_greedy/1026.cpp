#include <bits/stdc++.h>
using namespace std;

int a[50];
int b[50];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a,a+n,cmp);
    sort(b,b+n);
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        ans += a[i]*b[i];
    }
    
    cout << ans;
}