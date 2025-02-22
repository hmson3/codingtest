#include <bits/stdc++.h>
using namespace std;

int tri[502][502];
int d[502][502];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) 
            cin >> tri[i][j];
    
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= i; j++) {
            d[i][j] = max(d[i-1][j],d[i-1][j-1]) + tri[i][j];
        } 
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) { 
        ans = max(ans,d[n][j]);
    }
    cout << ans;
}