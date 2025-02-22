#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for(int i = 4; i <=10; i++) {
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << a[n] << '\n'; 
    }
}