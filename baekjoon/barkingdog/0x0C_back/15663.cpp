#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
vector<pair<int,int>> a;

bool cmp(pair<int,int> x, pair<int,int> y) {
    return x.first < y.first;
}

void func(int k) {
    if (k == m) {
        
        vector<pair<int,int>> v = {};
        for (int i = 0; i < m; i++) {
            if(a[arr[i]].second != 0) v.push_back(a[arr[i]]);
        }
        stable_sort(v.begin(),v.end(),cmp);
        if(v.size()) {
            if(v[0].second != 1) return;
        }
        for (int i = 1; i < v.size(); i++) {
            if(v[i-1].first == v[i].first) {
                if(v[i].second != v[i-1].second + 1) return;
            }
            else {
                if(v[i].second != 1) return;
            }
        }
        for (int i = 0; i < m; i++) {
            cout << a[arr[i]].first << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if(!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back({t,0});
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++) {
        if(a[i].first == a[i-1].first) {
            if(a[i-1].second == 0) a[i-1].second++;
            a[i].second = a[i-1].second+1;
        }
    }
    func(0);
}