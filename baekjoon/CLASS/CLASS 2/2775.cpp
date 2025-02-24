#include <bits/stdc++.h>
using namespace std;

int a[15][15];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int j = 1; j <=14; j++) {
        a[0][j] = j; 
        a[j][1] = 1;
    }
    for(int i = 1; i <= 14; i++) {
        for(int j = 2; j <=14; j++) {
            a[i][j] = a[i][j-1]+a[i-1][j];
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int k,n;
        cin >> k >> n;
        cout << a[k][n] <<'\n';
    }    
}