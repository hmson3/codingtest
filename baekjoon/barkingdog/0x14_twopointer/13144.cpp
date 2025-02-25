#include <bits/stdc++.h>
using namespace std;

int n;
int a[100000];
int idx[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int en = 0;
    long long ans = 0;
    for(int st = 0; st < n; st++) {
        while(en < n) {
            if(idx[a[en]]) {
                break;
            }
            idx[a[en]]++;
            en++;
        }
        ans += (en-st);
        idx[a[st]]--;
    }
    cout << ans;
}    