#include <bits/stdc++.h>
using namespace std;

int gdb(int a, int b) {
    if (a == 0) return b;
    return gdb(b % a, a);
}

int lcm(int a, int b) { return a / gdb(a, b) * b; }

int solve(int m, int n, int x, int y) {
    if(x == m) x = 0;
    if(y == n) y = 0;
    int l = lcm(m, n);
    for (int i = x; i <= l; i += m) {
        if(i == 0) continue;
        if (i % n == y) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << '\n';
    }
}
