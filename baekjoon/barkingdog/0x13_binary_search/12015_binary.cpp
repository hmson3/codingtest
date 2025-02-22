#include <bits/stdc++.h>
using namespace std;

int a[1000000];
vector<int> v;
int n;

int upper_idx(int target) {
    int st = 0;
    int en = v.size();
    while(st < en) {
        int mid = (st+en) / 2;
        if(v[mid] == target) return mid;
        if(v[mid] > target) {
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
        cin >> a[i];
    }
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (v.back() < a[i]) v.push_back(a[i]);
        else {
            v[upper_idx(a[i])] = a[i];
        }
    }
    cout << v.size();
}