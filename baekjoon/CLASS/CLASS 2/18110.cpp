#include <bits/stdc++.h>
using namespace std;

int n;
int a[300000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n==0) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    int ff = round(n*0.15f);
    sort(a,a+n);
    int sum = 0;
    for(int i = ff; i < n-ff; i++) {
        sum += a[i];
    }
    float fff = round(float(sum)/(n-ff*2));
    cout << fff;
}