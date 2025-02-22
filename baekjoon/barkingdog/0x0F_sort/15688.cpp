#include <bits/stdc++.h>
using namespace std;

int a[2000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        a[m+1000000]++;
    }
    for(int i = 0; i < 2000001; i++) {
        if(a[i]) {
            while(a[i]--) {
                cout << i-1000000 << '\n';
            }
        }
    }
}