#include<bits/stdc++.h>
using namespace std;

long long a[1000001];
long long l[1000001];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    long long su = 0;
    long long k = 0;
    for(int i = 0; i < m; i++) {
        cin >> l[i]; 
        k += l[i];
    }
    if(k > n) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < m; i++) {
        int ii;
        cin >> ii;
        su += ii * l[i]; 
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ck = 0;
    for(int i = 0; i < k; i++) ck += a[i];
    int ans = 0;
    if(su == ck) ans++;
    for(int i = k; i < n; i++) {
        ck = ck - a[i - k] + a[i];
        if(su == ck) ans++;
    }
    cout << ans;
}