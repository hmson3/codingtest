#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[1000];
vector<int> v;

int n;

int upper_idx(int target) {
    int st = 0;
    int en = v.size();
    while(st < en) {
        int mid = (st+en) / 2;
        if(a[v[mid]].first == target) return mid;
        if(a[v[mid]].first > target) {
            en = mid;
        }
        else { 
            st = mid + 1;
        }
    
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    v.push_back(0);
    a[0].second = 1;
    int t = 1;
    for (int i = 1; i < n; i++) {
        if (a[v.back()].first < a[i].first) {
            a[i].second = a[v.back()].second;
            v.push_back(i);
        }
        else {
            int k = upper_idx(a[i].first);
            a[i].second = a[v[k]].second + 1;
             v[k] = i;
        }
    }
    cout << v.size() << '\n';
    int idx = a[v.back()].second;
    for (int i = 0; i < n; i++) {
        if(a[i].second == idx) {
            cout << a[i].first << ' ';
        }
    }
}