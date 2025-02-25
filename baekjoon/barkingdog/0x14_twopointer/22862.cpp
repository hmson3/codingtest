#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int en = 0;
    int ans = 0;
    int hol = 0;
    int zzak = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && hol <= k) {
            if (a[en] % 2 == 1) {
                hol++;
            }
            else {
                zzak++;
            }
            en++;
        }
        ans = max(ans,zzak);
        if (a[st] % 2 == 1) hol--;
        else zzak--;
    }
    cout << ans;
}