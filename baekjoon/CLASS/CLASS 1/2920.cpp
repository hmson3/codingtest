#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[8] = {};
    for (int i = 0; i < 8; i++) cin >> a[i];

    int asc = 1;
    int des = 1;
    int mix = 1;
    for (int i = 1; i < 8; i++) {
        if (a[i - 1] < a[i]) {
            des = 0;
        } else if (a[i - 1] > a[i]) {
            asc = 0;
        }
    }
    if(asc == 1) cout << "ascending";
    else if(des == 1) cout << "descending";
    else cout << "mixed";
}