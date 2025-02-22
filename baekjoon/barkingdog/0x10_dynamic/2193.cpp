#include <bits/stdc++.h>
using namespace std;

long long a[91][2]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    
    a[1][0] = 0;
    a[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        a[i][0] = a[i-1][0] + a[i-1][1];
        a[i][1] = a[i-1][0];
    }
    cout << a[n][0]+a[n][1];
}