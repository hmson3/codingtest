#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        int m,vv;
        cin >> m >> vv;
        v.push_back({m,vv});
    }
    sort(v.begin(),v.end(),cmp);
    multiset<int> s;
    for(int i = 0; i < k; i++) {
        int m;
        cin >> m;
        s.insert(m);
    }
    long long ans = 0;
    for(int i = v.size()-1; i >= 0; i--) {
        auto c = s.lower_bound(v[i].first);
        if(c == s.end()) continue;
        s.erase(c);
        ans += v[i].second;
        if(s.empty()) break;
    }
    cout << ans;
}