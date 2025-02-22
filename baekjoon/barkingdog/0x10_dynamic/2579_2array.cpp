#include <bits/stdc++.h>
using namespace std;

int stair[305];
int a[305][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stair[i];
    }
    if(n == 1) { // 1인경우 a[2]에 접근하는게 바람직하지 않음
        cout << stair[0];
        return 0;
    }
    a[1][1] = stair[0];
    a[2][1] = stair[1];
    a[2][2] = a[1][1]+stair[1];

    for(int i = 3; i <=n; i++) {
        a[i][1] = max(a[i-2][1],a[i-2][2]) + stair[i-1];        
        a[i][2] = a[i-1][1]+stair[i-1];   
    }
    cout << max(a[n][1],a[n][2]);
}