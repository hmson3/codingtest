#include <bits/stdc++.h>
using namespace std;

pair<int,int> meee[100001];

bool cmp(pair<int,int> a, pair<int,int> b) { 
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second; 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> meee[i].first >> meee[i].second;
    sort(meee,meee+n,cmp);
    int last = meee[0].second;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if(last <= meee[i].first) {
            ans++;
            last = meee[i].second;
        }
    }
    cout << ans;
}