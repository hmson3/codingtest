#include <bits/stdc++.h>
using namespace std;

int n,ans;
pair<int,int> a[50];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for(int i = 0; i < n; i++) {
        ans = 0;
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            if(a[i].first < a[j].first && a[i].second < a[j].second) ans++;
        }
        cout << ans + 1 << ' ';
    }
}