#include <bits/stdc++.h>
using namespace std;

int a[1000000];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (v.back() < a[i]) v.push_back(a[i]);
        else {
            if(binary_search(v.begin(),v.end(),a[i])) continue;
            int k = upper_bound(v.begin(),v.end(),a[i]) - v.begin();
            v[k] = a[i];
        }
    }
    cout << v.size();
}