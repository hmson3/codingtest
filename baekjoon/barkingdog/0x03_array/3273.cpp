#include <bits/stdc++.h>
using namespace std;

int a[100001] = {};
bool c[2000001] = {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int w = 0;
    for(int i = 0; i < n; i++) {
        if(x-a[i] > 0 && c[x-a[i]]) w++;
        c[a[i]] = 1;
    }
    cout << w;
}