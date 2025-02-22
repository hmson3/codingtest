#include <bits/stdc++.h>
using namespace std;

int a[1000];
int d[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fill(d,d+1000,1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
        }
    }
    cout << *max_element(d, d + n);
}