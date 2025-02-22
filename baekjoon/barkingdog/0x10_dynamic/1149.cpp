#include <bits/stdc++.h>
using namespace std;

int house[1001][3];
int a[1001][3]; // d[i][j] : i번째를 j색깔로 채울때 최솟값값

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) 
        for(int j = 0; j < 3; j++)
            cin >> house[i][j];

    a[0][0] = house[0][0];
    a[0][1] = house[0][1];
    a[0][2] = house[0][2];

    for(int i = 1; i < n; i++) {
        a[i][0] = min(a[i-1][1],a[i-1][2]) + house[i][0];        
        a[i][1] = min(a[i-1][0],a[i-1][2]) + house[i][1];        
        a[i][2] = min(a[i-1][1],a[i-1][0]) + house[i][2];        
    }
    cout << min({a[n-1][0],a[n-1][1],a[n-1][2]});
}