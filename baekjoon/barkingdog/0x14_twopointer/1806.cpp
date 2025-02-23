#include <bits/stdc++.h>
using namespace std;

int a[100000];
int n,s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int st = 0; 
    int en = 1;
    int tmp = a[0];
    int ans = 100001;
    while(en <= n) {
        if(tmp >= s) {
            ans = min(ans,en-st);
            tmp -= a[st++];
            continue;
        }
        tmp += a[en++];
    }
    if(ans == 100001) cout << 0;
    else  cout << ans;
}