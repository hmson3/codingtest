#include <bits/stdc++.h>
using namespace std;

int a[100001]; 
 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;

    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        a[i] = a[i-1] + tmp;
    }

    for(int k = 0; k < m; k++) {
        int i,j;
        cin >> i >> j;
        cout << a[j] - a[i-1] << '\n';   
    }
}