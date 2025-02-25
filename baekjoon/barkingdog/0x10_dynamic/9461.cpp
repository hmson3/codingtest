#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[101];
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    for(int i = 4; i < 101; i++) {
        a[i] = a[i-2] + a[i-3];
    }
    int t;
    cin >> t;
    while(t--) {
        int i;
        cin >> i;
        cout << a[i] << '\n'; 
    }
}