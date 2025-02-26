#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[15];
int n;
int d[16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for(int i = n-1; i >= 0; i--) {
        if(i+a[i].first > n) continue;
        d[i] = *max_element(d+i+a[i].first,d+n) + a[i].second;
    }
    cout << *max_element(d,d+n);
}