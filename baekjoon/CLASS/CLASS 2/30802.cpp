#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a[6] = {};
    int t,p;
    cin >> n;
    for(int i = 0; i < 6; i++) cin >> a[i];
    cin >> t >> p;
    int tsum = 0;
    for(int i = 0; i < 6; i++) {
        if(a[i]) { // tsum += (a[i]+t-1)/t;
            if(a[i]%t == 0) tsum += a[i]/t;
            else tsum += a[i]/t+1;
        }
    }
    cout << tsum << '\n';
    cout << n/p << ' ' << n%p;    
}