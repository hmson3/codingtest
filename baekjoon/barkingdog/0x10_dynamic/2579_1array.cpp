// 관점을 바꿈
// d[k] : k번째 밟지 않을 때, k까지 밟지않을 계단의 합의 최솟값
// 점화식
// d[k] = min(d[k-2],d[k-3])+ s[k]

#include <bits/stdc++.h>
using namespace std;

int stair[305];
int a[305];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int tot = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stair[i];
        tot += stair[i];
    }
    if(n == 2) { // 1인경우 a[2]에 접근하는게 바람직하지 않음
        cout << tot;
        return 0;
    }
    a[0] = stair[0];
    a[1] = stair[1];
    a[2] = stair[2];

    for(int i = 3; i <=n; i++) {
        a[i] = min(a[i-2],a[i-3]) + stair[i];        
    }
    cout << tot - min(a[n-1-1],a[n-1-2]);
}