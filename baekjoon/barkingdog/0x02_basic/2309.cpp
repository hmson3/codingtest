#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[9] = {0, 0, 1, 1, 1, 1, 1, 1, 1};
    int s[9] = {};
    for (int i = 0; i < 9; i++) {
        cin >> s[i];
    }
    sort(s, s + 9);
    do {
        int su = 0;
        for (int i = 0; i < 9; i++) {
            if (a[i]) su += s[i];
        }
        if (su == 100) {
            for (int i = 0; i < 9; i++) {
                if (a[i]) cout << s[i] << '\n';
            }
            break;
        }
    } while (next_permutation(a,a+9));
}
