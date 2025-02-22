#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int pre[1000005];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a[1] = 0;

    for(int i = 2; i <=n; i++) {
        a[i] = a[i-1]+1;
        pre[i] = i-1;
        if(i%2 == 0 && a[i] > a[i/2]+1) {
            a[i] = a[i/2] + 1;
            pre[i] = i/2;
        }
        if(i%3 == 0 && a[i] > a[i/3]+1) {
            a[i] = a[i/3] + 1;
            pre[i] = i/3;
        }
        
    }
    cout << a[n] << '\n';
    int k = n;
    while(k != 0) {
        cout << k << ' ';
        k = pre[k];
    }
    
}