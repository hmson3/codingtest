#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int k;
        cin >> k;
        ans += (k*k)%10;
    }
    cout << ans%10;
}