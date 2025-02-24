#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;
        int xx = (n - 1) / h + 1;
        cout << (n - 1) % h + 1;
        if (xx >= 10)
            cout << xx << '\n';
        else
            cout << 0 << xx << '\n';
    }
}