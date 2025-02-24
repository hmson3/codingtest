#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==0 && b == 0 && c == 0) break;
        int m = max(a,b);
        int z = a+b-m;
        int longe = max(m,c);
        m = m+c-longe;
        if (longe*longe == m*m+z*z) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
}