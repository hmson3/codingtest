#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a[1] = 0;
    for(int i = 2; i <=n; i++) {
        if(i % 2 == 0 && i % 3 == 0) {
            a[i] = min(a[i-1]+1,a[i/2]+1);
            a[i] = min(a[i],a[i/3]+1);
        }
        else if(i % 2 == 0) {
            a[i] = min(a[i-1]+1,a[i/2]+1);
        }
        else if(i % 3 == 0) {
            a[i] = min(a[i-1]+1,a[i/3]+1);
        }
        else {
            a[i] = a[i-1]+1;
        }
    }
    cout << a[n];
    
}