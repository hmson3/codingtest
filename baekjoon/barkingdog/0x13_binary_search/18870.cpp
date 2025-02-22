#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1000005];
int c[1000005];
int n;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b,b+n);
    c[0] = b[0];
    int idx = 1;
    for (int i = 1; i < n; i++) {
        if(b[i] == b[i-1]) continue;
        c[idx++] = b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << lower_bound(c,c+idx,a[i])-c << ' ';
    }
}