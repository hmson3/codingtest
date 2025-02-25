#include <bits/stdc++.h>
using namespace std;

int n;
int a[500000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    float fff = float(sum)/n;
    int ffff = round(fff);
    cout << ffff << '\n';
    sort(a,a+n);
    cout << a[n/2] << '\n';
    int ans = 1;
    int m = 0;
    int idx = 0;
    int hm = 0;
    for(int i = 1; i < n; i++) {
        if(a[i-1] == a[i]) {
            ans++;
        }
        else {
            if(ans > m) {
                m = ans;
                hm = 0;
                idx = i-1;
            }
            else if(ans == m && hm < 1) {
                hm++;
                idx = i-1;
            }
            ans = 1;
        }
    }
    if(ans > m) {
        m = ans;
        hm = 0;
        idx = n-1;
    }
    else if(ans == m && hm < 1) {
        hm++;
        idx = n-1;
    }
    cout << a[idx] << '\n';
    cout << a[n-1] - a[0] << '\n';
}