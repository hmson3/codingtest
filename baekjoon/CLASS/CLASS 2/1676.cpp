#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n; i > 0; i--) {
        int tmp = i;
        while(tmp%5 == 0) {
            ans++;
            tmp /= 5;
        }
    }
    cout << ans;
}